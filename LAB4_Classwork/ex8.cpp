#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Function for Insertion Sort (used for smaller subarrays)
void insertionSort(int arr[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Take the last element as pivot
    int i = low - 1;  // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort algorithm
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // Recursively sort the left subarray
        quickSort(arr, pi + 1, high); // Recursively sort the right subarray
    }
}

// Hybrid Sort: Uses Quick Sort for larger arrays and Insertion Sort for small subarrays
void hybridSort(int arr[], int low, int high) {
    if (high - low + 1 <= 10) {
        insertionSort(arr, low, high);  // Use Insertion Sort for small subarrays
    }
    else {
        quickSort(arr, low, high);  // Use Quick Sort for larger arrays
    }
}

int main() {
    // Example array
    int arr[] = { 12, 11, 13, 5, 6, 7, 50, 17, 28, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Timing the Hybrid Sort algorithm
    auto start = high_resolution_clock::now();
    hybridSort(arr, 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    // Output the sorted array
    cout << "Sorted array using Hybrid Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Hybrid Sort took: " << duration.count() << " microseconds" << endl;

    // Compare performance with standard Quick Sort
    int* arr2 = new int[n];  // Dynamically allocate memory for a new array
    for (int i = 0; i < n; i++) {
        arr2[i] = arr[i];  // Copy values from the original array
    }

    start = high_resolution_clock::now();
    quickSort(arr2, 0, n - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    // Output the sorted array
    cout << "Sorted array using Quick Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    cout << "Quick Sort took: " << duration.count() << " microseconds" << endl;

    // Free dynamically allocated memory
    delete[] arr2;

    return 0;
}
