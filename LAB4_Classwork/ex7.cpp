#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Function for Insertion Sort (for small arrays)
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

// Function to merge two halves
void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int* left = new int[n1];   // Dynamically allocate memory for left array
    int* right = new int[n2];  // Dynamically allocate memory for right array

    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int i = 0; i < n2; i++)
        right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }

    // Free dynamically allocated memory
    delete[] left;
    delete[] right;
}

// Function for Merge Sort (for large arrays)
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);  // Sort the left half
        mergeSort(arr, mid + 1, high);  // Sort the right half
        merge(arr, low, mid, high);  // Merge the two halves
    }
}

// Hybrid Sort: Uses Insertion Sort for small arrays and Merge Sort for large arrays
void hybridSort(int arr[], int low, int high) {
    if (high - low <= 10) {
        insertionSort(arr, low, high);  // Use Insertion Sort for small arrays
    }
    else {
        mergeSort(arr, low, high);  // Use Merge Sort for larger arrays
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

    // Compare performance with standard Merge Sort
    int* arr2 = new int[n];  // Dynamically allocate memory for a new array
    for (int i = 0; i < n; i++) {
        arr2[i] = arr[i];  // Copy values from the original array
    }

    start = high_resolution_clock::now();
    mergeSort(arr2, 0, n - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    // Output the sorted array
    cout << "Sorted array using Merge Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    cout << "Merge Sort took: " << duration.count() << " microseconds" << endl;

    // Free dynamically allocated memory
    delete[] arr2;

    return 0;
}
