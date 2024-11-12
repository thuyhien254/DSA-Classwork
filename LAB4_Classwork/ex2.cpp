#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;

// Bubble Sort Implementation
void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Insertion Sort Implementation
void insertionSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort Implementation
void selectionSort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        std::swap(arr[i], arr[minIdx]);
    }
}

// Function to benchmark the sorting algorithms
void benchmarkSortingAlgorithms() {
    int sizes[] = { 100, 1000, 10000 }; // Array sizes to test
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    // Dynamically allocate memory for the time results arrays
    double* bubbleTimes = new double[num_sizes];
    double* insertionTimes = new double[num_sizes];
    double* selectionTimes = new double[num_sizes];

    // Iterate over different array sizes
    for (int idx = 0; idx < num_sizes; idx++) {
        int size = sizes[idx];

        // Dynamically allocate memory for arrays of size 'size'
        int* arrBubble = new int[size];
        int* arrInsertion = new int[size];
        int* arrSelection = new int[size];

        // Initialize arrays with random values
        for (int i = 0; i < size; i++) {
            int randomValue = rand() % 10000;
            arrBubble[i] = randomValue;
            arrInsertion[i] = randomValue;
            arrSelection[i] = randomValue;
        }

        // Time Bubble Sort
        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(arrBubble, size);
        auto end = std::chrono::high_resolution_clock::now();
        bubbleTimes[idx] = std::chrono::duration<double>(end - start).count();

        // Time Insertion Sort
        start = std::chrono::high_resolution_clock::now();
        insertionSort(arrInsertion, size);
        end = std::chrono::high_resolution_clock::now();
        insertionTimes[idx] = std::chrono::duration<double>(end - start).count();

        // Time Selection Sort
        start = std::chrono::high_resolution_clock::now();
        selectionSort(arrSelection, size);
        end = std::chrono::high_resolution_clock::now();
        selectionTimes[idx] = std::chrono::duration<double>(end - start).count();

        // Clean up dynamically allocated memory for the sorting arrays
        delete[] arrBubble;
        delete[] arrInsertion;
        delete[] arrSelection;

        // Print the results for each sorting algorithm
        cout << "Array size: " << size << endl;
        cout << "Bubble Sort Time: " << bubbleTimes[idx] << " seconds" << endl;
        cout << "Insertion Sort Time: " << insertionTimes[idx] << " seconds" << endl;
        cout << "Selection Sort Time: " << selectionTimes[idx] << " seconds" << endl;
        cout << "-------------------------------" << endl;
    }

    // Clean up dynamically allocated memory for time result arrays
    delete[] bubbleTimes;
    delete[] insertionTimes;
    delete[] selectionTimes;
}

// Main function to run the benchmarking
int main() {
    // Seed the random number generator
    srand(time(0));

    // Run the sorting algorithm benchmark
    benchmarkSortingAlgorithms();

    return 0;
}
