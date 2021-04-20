#include "sorts.h"
#include "profile.h"

#include <iostream>
#include <vector>
#include <random>
#include <algorithm> 
#include <functional>
#include <limits> 

using namespace std;

std::vector<int> random_vector(size_t size_, int min_, int max_) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<> dis(min_, max_);

	std::vector<int> v(size_);
	generate(v.begin(), v.end(), std::bind(dis, std::ref(mt)));
	return v;
}

void print(const vector<int>& v) {
	for (size_t i = 0; i < min(static_cast<size_t>(10), v.size()); ++i) {
		cout << v[i] << ' ';
	}
	if (v.size() > 10) {
		for (size_t i = max(static_cast<size_t>(10), v.size() - 10); i < v.size(); ++i) {
			cout << v[i] << ' ';
		}
	}
	cout << '\n';
}

void testBubbleSort(vector<int> values);
void testShakerSort(vector<int> values);
void testCombSort(vector<int> values);
void testInsertionSort(vector<int> values);
void testSelectionSort(vector<int> values);
void testQuickSort(vector<int> values);
void testMergeSort(vector<int> values);
void testHeapSort(vector<int> values);
void testStdSort(vector<int> values);

void TestSorts() {
	vector<int> values = random_vector(10000, INT_MIN, INT_MAX);

	testBubbleSort(values);
	testShakerSort(values);
	testCombSort(values);
	testInsertionSort(values);
	testSelectionSort(values);
	testQuickSort(values);
	testMergeSort(values);
	testHeapSort(values);
	testStdSort(values);
}

int main()
{
	TestSorts();
	return 0;
}


void testBubbleSort(vector<int> values) {
	{
		LOG_DURATION("Bubble sort");
		bubbleSort(values);
	}
	cout << "Is sorted: " << is_sorted(values.begin(), values.end()) << endl;
}

void testShakerSort(vector<int> values) {
	{
		LOG_DURATION("Shaker sort");
		shakerSort(values);
	}
	cout << "Is sorted: " << is_sorted(values.begin(), values.end()) << endl;
}

void testCombSort(vector<int> values) {
	{
		LOG_DURATION("Comb sort");
		combSort(values);
	}
	cout << "Is sorted: " << is_sorted(values.begin(), values.end()) << endl;
}

void testInsertionSort(vector<int> values) {
	{
		LOG_DURATION("Insertion sort");
		insertionSort(values);
	}
	cout << "Is sorted: " << is_sorted(values.begin(), values.end()) << endl;
}

void testSelectionSort(vector<int> values) {
	{
		LOG_DURATION("Selection sort");
		selectionSort(values);
	}
	cout << "Is sorted: " << is_sorted(values.begin(), values.end()) << endl;
}

void testQuickSort(vector<int> values) {
	{
		LOG_DURATION("Quick sort");
		quickSort(values);
	}
	cout << "Is sorted: " << is_sorted(values.begin(), values.end()) << endl;
}

void testMergeSort(vector<int> values) {
	{
		LOG_DURATION("Merge sort");
		mergeSort(values);
	}
	cout << "Is sorted: " << is_sorted(values.begin(), values.end()) << endl;
}

void testHeapSort(vector<int> values) {
	{
		LOG_DURATION("Heap sort");
		heapSort(values);
	}
	cout << "Is sorted: " << is_sorted(values.begin(), values.end()) << endl;
}

void testStdSort(vector<int> values) {
	{
		LOG_DURATION("Std sort");
		sort(values.begin(), values.end());
	}
	cout << "Is sorted: " << is_sorted(values.begin(), values.end()) << endl;
}