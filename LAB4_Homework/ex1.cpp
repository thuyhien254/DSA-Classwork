#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct Product {
    string name;
    float price;
    float rating;
    int popularity; // For simplicity, popularity can be represented as an integer

    // Default constructor
    Product() : name(""), price(0.0), rating(0.0), popularity(0) {}

    // Constructor with parameters
    Product(string n, float p, float r, int pop) : name(n), price(p), rating(r), popularity(pop) {}
};

// Display a list of products
void displayProducts(Product products[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Name: " << products[i].name << ", Price: $" << products[i].price
            << ", Rating: " << products[i].rating << ", Popularity: " << products[i].popularity << endl;
    }
}

// Quick Sort
int partition(Product arr[], int low, int high, string criteria) {
    Product pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        bool shouldSwap = false;
        if (criteria == "price") {
            if (arr[j].price < pivot.price) shouldSwap = true;
        }
        else if (criteria == "rating") {
            if (arr[j].rating < pivot.rating) shouldSwap = true;
        }
        else if (criteria == "popularity") {
            if (arr[j].popularity < pivot.popularity) shouldSwap = true;
        }

        if (shouldSwap) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Product arr[], int low, int high, string criteria) {
    if (low < high) {
        int pi = partition(arr, low, high, criteria);
        quickSort(arr, low, pi - 1, criteria);
        quickSort(arr, pi + 1, high, criteria);
    }
}

// Merge Sort
void merge(Product arr[], int l, int m, int r, string criteria) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Product* L = new Product[n1];
    Product* R = new Product[n2];

    for (int i = 0; i < n1; ++i) L[i] = arr[l + i];
    for (int i = 0; i < n2; ++i) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        bool shouldSwap = false;
        if (criteria == "price") {
            if (L[i].price <= R[j].price) shouldSwap = true;
        }
        else if (criteria == "rating") {
            if (L[i].rating <= R[j].rating) shouldSwap = true;
        }
        else if (criteria == "popularity") {
            if (L[i].popularity <= R[j].popularity) shouldSwap = true;
        }

        if (shouldSwap) {
            arr[k] = L[i];
            ++i;
        }
        else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(Product arr[], int l, int r, string criteria) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m, criteria);
    mergeSort(arr, m + 1, r, criteria);
    merge(arr, l, m, r, criteria);
}

// Bubble Sort
void bubbleSort(Product arr[], int n, string criteria) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            bool shouldSwap = false;
            if (criteria == "price") {
                if (arr[j].price > arr[j + 1].price) shouldSwap = true;
            }
            else if (criteria == "rating") {
                if (arr[j].rating > arr[j + 1].rating) shouldSwap = true;
            }
            else if (criteria == "popularity") {
                if (arr[j].popularity > arr[j + 1].popularity) shouldSwap = true;
            }

            if (shouldSwap) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to generate random product data
void generateRandomProducts(Product arr[], int n) {
    string names[] = { "Product1", "Product2", "Product3", "Product4", "Product5" };
    for (int i = 0; i < n; ++i) {
        string name = names[rand() % 5];
        float price = rand() % 100 + 1;  // Random price between 1 and 100
        float rating = rand() % 5 + 1;  // Random rating between 1 and 5
        int popularity = rand() % 1000;  // Random popularity score
        arr[i] = Product(name, price, rating, popularity);
    }
}

// Function to measure time taken by a sorting algorithm
template <typename Func>
void measureTime(Func sortFunc, Product arr[], int n, string criteria) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc(arr, 0, n - 1, criteria);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Sorting by " << criteria << " took: " << duration.count() << " seconds" << endl;
}

int main() {
    srand(time(0));

    const int n = 1000;  // Number of products
    Product products[n];

    generateRandomProducts(products, n);

    int choice, sortChoice;
    string criteria;

    // Main menu for user interaction
    do {
        cout << "E-Commerce Product Sorting" << endl;
        cout << "1. Sort by Price" << endl;
        cout << "2. Sort by Rating" << endl;
        cout << "3. Sort by Popularity" << endl;
        cout << "4. Exit" << endl;
        cout << "Select the sorting criteria (1-3): ";
        cin >> choice;

        switch (choice) {
        case 1:
            criteria = "price";
            break;
        case 2:
            criteria = "rating";
            break;
        case 3:
            criteria = "popularity";
            break;
        default:
            cout << "Invalid choice!" << endl;
            continue;
        }

        // Sorting algorithm selection
        cout << "\nSelect sorting algorithm:" << endl;
        cout << "1. Quick Sort" << endl;
        cout << "2. Merge Sort" << endl;
        cout << "3. Bubble Sort" << endl;
        cout << "Select the sorting algorithm (1-3): ";
        cin >> sortChoice;

        Product sortedProducts[n];
        copy(begin(products), end(products), begin(sortedProducts));

        switch (sortChoice) {
        case 1:
            measureTime([](Product arr[], int low, int high, string criteria) { quickSort(arr, low, high, criteria); }, sortedProducts, n, criteria);
            break;
        case 2:
            measureTime([](Product arr[], int low, int high, string criteria) { mergeSort(arr, low, high, criteria); }, sortedProducts, n, criteria);
            break;
        case 3:
            measureTime([](Product arr[], int low, int high, string criteria) { bubbleSort(arr, high + 1, criteria); }, sortedProducts, n, criteria);
            break;
        default:
            cout << "Invalid algorithm choice!" << endl;
            continue;
        }

        displayProducts(sortedProducts, n);

        cout << "\nDo you want to sort again? (1 for Yes, 0 for No): ";
        cin >> choice;
    } while (choice == 1);

    return 0;
}
