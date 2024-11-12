#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // Left child index
    int right = 2 * i + 2; // Right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to build a Max Heap
void buildMaxHeap(int arr[], int n) {
    // Start from the last non-leaf node and heapify each subtree
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Function to find the maximum value without fully sorting
int findMax(int arr[], int n) {
    // Build a Max Heap
    buildMaxHeap(arr, n);

    // The root of the Max Heap will be the maximum value
    return arr[0];
}

int main() {
    int arr[] = { 12, 7, 9, 15, 10, 1, 3, 8 }; // Example array
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Find the maximum value using Max Heap
    int maxVal = findMax(arr, n);
    cout << "Maximum value: " << maxVal << endl;

    return 0;
}
