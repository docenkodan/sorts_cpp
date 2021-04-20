#pragma once

#include <vector>
#include <algorithm>

// Bubble sort - Сортировка пузырьком
void bubbleSort(std::vector<int>& values) {
	bool is_sorted = false;
	for (size_t i = 0; i + 1 < values.size() && !is_sorted; ++i) {
		is_sorted = true;
		for (size_t j = 0; j + 1 < values.size() - i; ++j) {
			if (values[j + 1] < values[j]) {
				std::swap(values[j + 1], values[j]);
				is_sorted = false;
			}
		}
	}
}

// Stirred sorting (shaker sort) - Шейкерная сортировка
void shakerSort(std::vector<int>& values) {
	if (values.empty()) {
		return;
	}

	size_t left = 0;
	size_t right = values.size() - 1;
	while (left <= right) {
		for (size_t i = right; i > left; --i) {
			if (values[i - 1] > values[i]) {
				std::swap(values[i - 1], values[i]);
			}
		}
		left++;
		for (size_t i = left; i < right; ++i) {
			if (values[i] > values[i + 1]) {
				std::swap(values[i], values[i + 1]);
			}
		}
		right--;
	}
}

// Comb sort - Сортировка расчёской
void combSort(std::vector<int>& values) {
	const double factor = 1.247; // Фактор уменьшения
	double step = values.size() - 1;

	while (step >= 1) {
		for (size_t i = 0; i + step < values.size(); ++i) {
			if (values[i] > values[i + step]) {
				std::swap(values[i], values[i + step]);
			}
		}
		step /= factor;
	}

	//Сортировка пузырьком
	bubbleSort(values);
}

// Insertion Sort - Сортировка вставками
void insertionSort(std::vector<int>& values) {
	for (size_t i = 1; i < values.size(); ++i) {
		int value = values[i];
		size_t j = i;
		for (; j > 0 && values[j - 1] > value; --j) {
			values[j] = values[j - 1];
		}
		values[j] = value;
	}
}

// Selection Sort - Сортировка выбором
void selectionSort(std::vector<int>& values) {
	for (auto i = values.begin(); i != values.end(); ++i) {
		auto j = std::min_element(i, values.end());
		std::swap(*i, *j);
	}
}

// Quick Sort - Быстрая сортировка
int quickSortPartition(std::vector<int>& values, int l, int r) {
	int value = values[r];
	int less = l;

	for (int i = l; i < r; ++i) {
		if (values[i] <= value) {
			std::swap(values[i], values[less]);
			less++;
		}
	}
	std::swap(values[less], values[r]);
	return less;
}

void quickSortImpl(std::vector<int>& values, int left, int right) {
	if (left < right) {
		int middle = quickSortPartition(values, left, right);
		quickSortImpl(values, left, middle - 1);
		quickSortImpl(values, middle + 1, right);
	}
}

void quickSort(std::vector<int>& values) {
	if (!values.empty()) {
		quickSortImpl(values, 0, values.size() - 1);
	}
}

// Merge Sort - Сортировка слиянием
void mergeSortImpl(std::vector<int>& values, std::vector<int>& buffer, int left, int right) {
	if (left < right) {
		int middle = (left + right) / 2;
		mergeSortImpl(values, buffer, left, middle);
		mergeSortImpl(values, buffer, middle + 1, right);

		int k = left;
		for (int i = left, j = middle + 1; i <= middle || j <= right; ) {
			if (j > right || (i <= middle && values[i] < values[j])) {
				buffer[k] = values[i];
				++i;
			}
			else {
				buffer[k] = values[j];
				++j;
			}
			++k;
		}
		for (int i = left; i <= right; ++i) {
			values[i] = buffer[i];
		}
	}
}

void mergeSort(std::vector<int>& values) {
	if (!values.empty()) {
		std::vector<int> buffer(values.size());
		mergeSortImpl(values, buffer, 0, values.size() - 1);
	}
}

// Heap Sort - Пирамидальная сортировка
void heapSort(std::vector<int>& values) {
	std::make_heap(values.begin(), values.end());
	for (auto i = values.end(); i != values.begin(); --i) {
		std::pop_heap(values.begin(), i);
	}
}