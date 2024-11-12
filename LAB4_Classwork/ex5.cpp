#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Binary Search function to find the index where the element should be inserted
int binarySearch(const vector<int>& arr, int item, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == item)
            return mid + 1;
        else if (arr[mid] < item)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

// Enhanced Insertion Sort with Binary Search
void insertionSortBinary(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int item = arr[i];
        // Find position to insert using binary search
        int pos = binarySearch(arr, item, 0, i - 1);
        // Shift elements to make room for item
        for (int j = i; j > pos; --j) {
            arr[j] = arr[j - 1];
        }
        arr[pos] = item;
    }
}

// Standard Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to measure execution time
template <typename Func>
long long timeSort(Func sortFunction, vector<int> arr) {
    auto start = high_resolution_clock::now();
    sortFunction(arr);
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();
}

int main() {
    // Generate a large random array for testing
    const int size = 10000;
    vector<int> arr(size);
    for (int& val : arr) {
        val = rand() % 10000;
    }

    vector<int> arrCopy = arr;

    // Measure time for standard insertion sort
    cout << "Standard Insertion Sort took " << timeSort(insertionSort, arr) << " microseconds." << endl;

    // Measure time for binary insertion sort
    cout << "Binary Insertion Sort took " << timeSort(insertionSortBinary, arrCopy) << " microseconds." << endl;

    return 0;
}
