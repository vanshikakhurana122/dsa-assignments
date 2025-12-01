#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
	int start = 0;
	int end = n - 1;

	while (start < end) {
		int minIndex = start;
		int maxIndex = start;

		// find both min and max in the unsorted part
		for (int i = start; i <= end; i++) {
			if (arr[i] < arr[minIndex])
				minIndex = i;
			if (arr[i] > arr[maxIndex])
				maxIndex = i;
		}

		// place minimum at the beginning
		if (minIndex != start) {
			int temp = arr[start];
			arr[start] = arr[minIndex];
			arr[minIndex] = temp;
		}

		// if max was at start, its position changed after min swap
		if (maxIndex == start)
			maxIndex = minIndex;

		// place maximum at the end
		if (maxIndex != end) {
			int temp = arr[end];
			arr[end] = arr[maxIndex];
			arr[maxIndex] = temp;
		}

		start++;
		end--;
	}
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main() {
	int n;
	cout << "enter number of elements: ";
	cin >> n;

	int arr[n];
	cout << "enter " << n << " elements: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << "unsorted array: ";
	printArray(arr, n);

	improvedSelectionSort(arr, n);

	cout << "sorted array: ";
	printArray(arr, n);

	return 0;
}
