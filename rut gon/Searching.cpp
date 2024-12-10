#include <iostream>
#include <cmath>
#include <algorithm> // Để sử dụng hàm sort
using namespace std;

// 1. Linear Search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return i; // Trả về chỉ số nếu tìm thấy
    }
    return -1; // Không tìm thấy
}

// 2. Binary Search
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) return mid; // Tìm thấy
        else if (arr[mid] < target) left = mid + 1; // Tìm bên phải
        else right = mid - 1; // Tìm bên trái
    }
    return -1; // Không tìm thấy
}

// 3. Jump Search
int jumpSearch(int arr[], int size, int target) {
    int step = sqrt(size);
    int prev = 0;

    while (arr[min(step, size) - 1] < target) {
        prev = step;
        step += sqrt(size);
        if (prev >= size) return -1; // Không tìm thấy
    }

    // Duyệt tuyến tính trong khoảng
    for (int i = prev; i < min(step, size); i++) {
        if (arr[i] == target) return i;
    }
    return -1; // Không tìm thấy
}

// 4. Interpolation Search
int interpolationSearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) return low;
            return -1;
        }

        int pos = low + ((double)(high - low) / (arr[high] - arr[low]) * (target - arr[low]));

        if (arr[pos] == target) return pos; // Tìm thấy
        else if (arr[pos] < target) low = pos + 1; // Tìm bên phải
        else high = pos - 1; // Tìm bên trái
    }
    return -1; // Không tìm thấy
}

// 5. Kth Smallest Element
int kthSmallest(int arr[], int size, int k) {
    sort(arr, arr + size); // Sắp xếp mảng
    return arr[k - 1]; // Phần tử nhỏ thứ k
}

// 6. Count Occurrences
int countOccurrences(int arr[], int size, int target) {
    int first = binarySearch(arr, 0, size - 1, target);
    if (first == -1) return 0; // Không tìm thấy

    int count = 1;
    int left = first - 1;
    while (left >= 0 && arr[left] == target) {
        count++;
        left--;
    }

    int right = first + 1;
    while (right < size && arr[right] == target) {
        count++;
        right++;
    }

    return count; // Số lần xuất hiện
}

// Main function for testing
int main() {
    int arr[] = {10, 20, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Linear Search for 20: " << linearSearch(arr, size, 20) << endl;
    cout << "Binary Search for 30: " << binarySearch(arr, 0, size - 1, 30) << endl;
    cout << "Jump Search for 40: " << jumpSearch(arr, size, 40) << endl;
    cout << "Interpolation Search for 50: " << interpolationSearch(arr, size, 50) << endl;
    cout << "Kth Smallest Element (k=3): " << kthSmallest(arr, size, 3) << endl;
    cout << "Count Occurrences of 20: " << countOccurrences(arr, size, 20) << endl;

    return 0;
}
