#include <iostream>
#include <algorithm> // Để sử dụng hàm swap
#include <cmath>     // Để dùng sqrt trong Counting/Radix Sort
using namespace std;

// 1. Bubble Sort
void bubbleSort(int arr[], int n){
    for(int i=0; i < n-1;i++){
        for(int j=0; j < n -i-1;j++){
            if(arr[j] > arr[j+1]){
                swap (arr[j],arr[j+1]);
            }
        }
    }
}

// 2. Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i; // Khởi tạo phần tử nhỏ nhất là i
        for (int j = i + 1; j < n; j++) { // Tìm phần tử nhỏ nhất sau i
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr[i], arr[min]); // Đổi chỗ phần tử nhỏ nhất về vị trí i
    }
}


// 3. Insertion Sort
void insertionSort(int arr[], int n){
    for(int i=0; i< n; i++){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j]> key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// 4. Binary Insertion Sort
int binarySearch(int arr[], int item, int low, int high){
    while (low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid]== item) return mid +1;
        else if(arr[mid] < item) return low = mid +1;
        else return high = mid -1;
    }
}

void binaryInsertionSort(int arr[], int n){
    for(int i=0; i < n; i++){
        int key = arr[i];
        int pos = binarySearch(arr,key,0,i-1);
        for(int j = i-1; j >= pos; j--){
            arr[j+1] = arr[j];
        }
        arr[pos] = key;
    }
}

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // chọn pivot là số cuối cùng
    int i = low - 1;
    for (int j = low; j < high; j++) { // những số lớn hơn pivot thì đổi chỗ với những số lớn hơn pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // đem pivot vô giữa chia đôi ra
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1); // đệ quy cho nửa trái
        quickSort(arr, pi + 1, high); // đệ quy cho nửa phải
    }
}

// 6. Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Kích thước mảng trái
    int n2 = right - mid;    // Kích thước mảng phải

    int L[n1], R[n2]; // Tạo mảng tạm cho hai nửa

    // Copy dữ liệu vào mảng tạm
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    // Trộn hai mảng
    int i = 0, j = 0, k = left; // Chỉ số i cho L[], j cho R[], k cho arr[]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của L[], nếu có
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của R[], nếu có
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Tìm điểm giữa

        mergeSort(arr, left, mid);         // Sắp xếp nửa trái
        mergeSort(arr, mid + 1, right);    // Sắp xếp nửa phải

        merge(arr, left, mid, right);      // Trộn hai nửa
    }
}

// 7. Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;           // Gốc ban đầu
    int left = 2 * i + 1;      // Con trái
    int right = 2 * i + 2;     // Con phải

    // Nếu con trái lớn hơn gốc
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Nếu con phải lớn hơn gốc
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Nếu gốc không phải là lớn nhất
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Đệ quy xuống cây con
    }
}

void heapSort(int arr[], int n) {
    // Bước 1: Xây dựng Max-Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Bước 2: Trích xuất từng phần tử từ Heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Đưa phần tử lớn nhất về cuối
        heapify(arr, i, 0);    // Gọi heapify cho phần còn lại
    }
}


// 8. Counting Sort
void countingSort(int arr[], int n, int maxVal) {
    // Tạo mảng đếm và mảng kết quả
    int* count = new int[maxVal + 1](); // Khởi tạo tất cả giá trị là 0
    int* output = new int[n];

    // Bước 1: Đếm số lần xuất hiện
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Bước 2: Tích lũy số lần xuất hiện
    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }

    // Bước 3: Sắp xếp mảng
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Sao chép mảng kết quả vào mảng ban đầu
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Giải phóng bộ nhớ
    delete[] count;
    delete[] output;
}


// 9. Radix Sort
void radixSort(int arr[], int n);
void countingSortForRadix(int arr[], int n, int exp);

// Utility functions
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    // 1. Bubble Sort
    int bubbleArr[] = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(bubbleArr, n);
    cout << "Bubble Sorted array: ";
    printArray(bubbleArr, n);

    // 2. Selection Sort
    int selectionArr[] = {64, 34, 25, 12, 22, 11, 90};
    selectionSort(selectionArr, n);
    cout << "Selection Sorted array: ";
    printArray(selectionArr, n);

    // 3. Insertion Sort
    int insertionArr[] = {64, 34, 25, 12, 22, 11, 90};
    insertionSort(insertionArr, n);
    cout << "Insertion Sorted array: ";
    printArray(insertionArr, n);

    // 4. Binary Insertion Sort
    int binaryInsertionArr[] = {64, 34, 25, 12, 22, 11, 90};
    binaryInsertionSort(binaryInsertionArr, n);
    cout << "Binary Insertion Sorted array: ";
    printArray(binaryInsertionArr, n);

    // 5. Quick Sort
    int quickArr[] = {64, 34, 25, 12, 22, 11, 90};
    quickSort(quickArr, 0, n - 1);
    cout << "Quick Sorted array: ";
    printArray(quickArr, n);

    // 6. Merge Sort
    int mergeArr[] = {64, 34, 25, 12, 22, 11, 90};
    mergeSort(mergeArr, 0, n - 1);
    cout << "Merge Sorted array: ";
    printArray(mergeArr, n);

    // 7. Heap Sort
    int heapArr[] = {64, 34, 25, 12, 22, 11, 90};
    heapSort(heapArr, n);
    cout << "Heap Sorted array: ";
    printArray(heapArr, n);

    // 8. Counting Sort
    int countingArr[] = {64, 34, 25, 12, 22, 11, 90};
    int maxVal = *max_element(countingArr, countingArr + n);
    countingSort(countingArr, n, maxVal);
    cout << "Counting Sorted array: ";
    printArray(countingArr, n);

    return 0;
}
