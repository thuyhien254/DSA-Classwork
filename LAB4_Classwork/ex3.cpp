#include <iostream>
#include <string>
using namespace std;

// Bubble Sort function
template <typename T>
void bubbleSort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Insertion Sort function
template <typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; ++i) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort function
template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Function to print an array
template <typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Test with integers
    int intArr[] = { 5, 3, 8, 6, 2, 7 };
    int intSize = sizeof(intArr) / sizeof(intArr[0]);

    cout << "Bubble Sort (Integers): ";
    bubbleSort(intArr, intSize);
    printArray(intArr, intSize);

    cout << "Insertion Sort (Integers): ";
    insertionSort(intArr, intSize);
    printArray(intArr, intSize);

    cout << "Selection Sort (Integers): ";
    selectionSort(intArr, intSize);
    printArray(intArr, intSize);

    // Test with floating-point numbers
    float floatArr[] = { 2.5, 3.1, 1.8, 7.6, 4.4 };
    int floatSize = sizeof(floatArr) / sizeof(floatArr[0]);

    cout << "Bubble Sort (Floats): ";
    bubbleSort(floatArr, floatSize);
    printArray(floatArr, floatSize);

    cout << "Insertion Sort (Floats): ";
    insertionSort(floatArr, floatSize);
    printArray(floatArr, floatSize);

    cout << "Selection Sort (Floats): ";
    selectionSort(floatArr, floatSize);
    printArray(floatArr, floatSize);

    // Test with strings
    string stringArr[] = { "apple", "orange", "banana", "pear", "grape" };
    int stringSize = sizeof(stringArr) / sizeof(stringArr[0]);

    cout << "Bubble Sort (Strings): ";
    bubbleSort(stringArr, stringSize);
    printArray(stringArr, stringSize);

    cout << "Insertion Sort (Strings): ";
    insertionSort(stringArr, stringSize);
    printArray(stringArr, stringSize);

    cout << "Selection Sort (Strings): ";
    selectionSort(stringArr, stringSize);
    printArray(stringArr, stringSize);

    return 0;
}
