#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Structure to represent a point in 2D space
struct Point {
    int x, y;
    // Constructor to initialize the point
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Function to calculate squared distance from the origin
    int distanceSquared() const {
        return x * x + y * y;  // We use squared distance to avoid unnecessary square root calculation
    }
};

// Bubble Sort for sorting points based on distance from the origin
void bubbleSort(Point arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j].distanceSquared() > arr[j + 1].distanceSquared()) {
                // Swap points if they are out of order
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Insertion Sort for sorting points based on distance from the origin
void insertionSort(Point arr[], int n) {
    for (int i = 1; i < n; i++) {
        Point key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key's distance
        // from the origin to one position ahead of their current position
        while (j >= 0 && arr[j].distanceSquared() > key.distanceSquared()) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Quick Sort algorithm for sorting points based on distance from the origin
int partition(Point arr[], int low, int high) {
    int pivotDist = arr[high].distanceSquared();  // Get distance of pivot from the origin
    int i = low - 1;

    // Partitioning step
    for (int j = low; j < high; j++) {
        if (arr[j].distanceSquared() <= pivotDist) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Point arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);  // Sort the left half
        quickSort(arr, pi + 1, high); // Sort the right half
    }
}

int main() {
    // Array of points (2D coordinates)
    Point points[] = { Point(3, 4), Point(1, 2), Point(5, 12), Point(0, 0), Point(8, 15) };
    int n = sizeof(points) / sizeof(points[0]);

    // Print the points before sorting
    cout << "Original points:\n";
    for (int i = 0; i < n; i++) {
        cout << "(" << points[i].x << ", " << points[i].y << ")\n";
    }

    // Bubble Sort
    auto start = high_resolution_clock::now();
    bubbleSort(points, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\nPoints sorted by Bubble Sort (distance from origin):\n";
    for (int i = 0; i < n; i++) {
        cout << "(" << points[i].x << ", " << points[i].y << ")\n";
    }
    cout << "Bubble Sort took: " << duration.count() << " microseconds\n";

    // Reset points to original values for next sorting algorithm
    Point points2[] = { Point(3, 4), Point(1, 2), Point(5, 12), Point(0, 0), Point(8, 15) };

    // Insertion Sort
    start = high_resolution_clock::now();
    insertionSort(points2, n);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "\nPoints sorted by Insertion Sort (distance from origin):\n";
    for (int i = 0; i < n; i++) {
        cout << "(" << points2[i].x << ", " << points2[i].y << ")\n";
    }
    cout << "Insertion Sort took: " << duration.count() << " microseconds\n";

    // Reset points to original values for next sorting algorithm
    Point points3[] = { Point(3, 4), Point(1, 2), Point(5, 12), Point(0, 0), Point(8, 15) };

    // Quick Sort
    start = high_resolution_clock::now();
    quickSort(points3, 0, n - 1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "\nPoints sorted by Quick Sort (distance from origin):\n";
    for (int i = 0; i < n; i++) {
        cout << "(" << points3[i].x << ", " << points3[i].y << ")\n";
    }
    cout << "Quick Sort took: " << duration.count() << " microseconds\n";

    return 0;
}
