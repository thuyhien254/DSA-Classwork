#include <iostream>
#include <chrono>
#include <cstdlib> // For rand and srand
#include <ctime>   // For time
using namespace std;

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

// Function to generate random array
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
}

// Function to copy array
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

// Function to measure sorting time
template <typename Func>
void measureTime(Func sortFunc, int arr[], int n, const string& name) {
    int* tempArr = new int[n];
    copyArray(arr, tempArr, n);

    auto start = chrono::high_resolution_clock::now();
    sortFunc(tempArr, n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;

    cout << name << " took " << duration.count() << " ms" << endl;
    delete[] tempArr;
}

int main() {
    srand(time(0));
    const int n = 1000;
    int arr[n];
    generateRandomArray(arr, n);

    cout << "Sorting 1000 random integers:\n";
    measureTime(bubbleSort, arr, n, "Bubble Sort");
    measureTime(insertionSort, arr, n, "Insertion Sort");
    measureTime(selectionSort, arr, n, "Selection Sort");

    return 0;
}
