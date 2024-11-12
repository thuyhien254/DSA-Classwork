#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>

using namespace std;

// Student structure with default and parameterized constructors
struct Student {
    string name;  // Student's name
    int grade;    // Student's grade (score)
    int age;      // Student's age

    // Default constructor
    Student() : name(""), grade(0), age(0) {}

    // Parameterized constructor
    Student(string n, int g, int a) : name(n), grade(g), age(a) {}
};

// Function to display students
void displayStudents(Student students[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Name: " << students[i].name << ", Grade: " << students[i].grade << ", Age: " << students[i].age << endl;
    }
    cout << "---------------------------\n";
}

// Quick Sort function
int partition(Student students[], int low, int high, const string& criteria) {
    Student pivot = students[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        bool shouldSwap = false;
        if (criteria == "grade" && students[j].grade < pivot.grade) shouldSwap = true;
        else if (criteria == "name" && students[j].name < pivot.name) shouldSwap = true;
        else if (criteria == "age" && students[j].age < pivot.age) shouldSwap = true;

        if (shouldSwap) {
            ++i;
            swap(students[i], students[j]);
        }
    }

    swap(students[i + 1], students[high]);
    return i + 1;
}

void quickSort(Student students[], int low, int high, const string& criteria) {
    if (low < high) {
        int pi = partition(students, low, high, criteria);
        quickSort(students, low, pi - 1, criteria);
        quickSort(students, pi + 1, high, criteria);
    }
}

// Merge Sort functions
void merge(Student students[], int l, int m, int r, const string& criteria) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Student* L = new Student[n1]; // Allocate memory for left subarray
    Student* R = new Student[n2]; // Allocate memory for right subarray

    for (int i = 0; i < n1; ++i)
        L[i] = students[l + i];
    for (int i = 0; i < n2; ++i)
        R[i] = students[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        bool shouldSwap = false;
        if (criteria == "grade" && L[i].grade <= R[j].grade) shouldSwap = true;
        else if (criteria == "name" && L[i].name <= R[j].name) shouldSwap = true;
        else if (criteria == "age" && L[i].age <= R[j].age) shouldSwap = true;

        if (shouldSwap) {
            students[k] = L[i];
            ++i;
        }
        else {
            students[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        students[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        students[k] = R[j];
        ++j;
        ++k;
    }

    delete[] L; // Free allocated memory
    delete[] R; // Free allocated memory
}

void mergeSort(Student students[], int l, int r, const string& criteria) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(students, l, m, criteria);
        mergeSort(students, m + 1, r, criteria);
        merge(students, l, m, r, criteria);
    }
}

// Bubble Sort function
void bubbleSort(Student students[], int size, const string& criteria) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            bool shouldSwap = false;
            if (criteria == "grade" && students[j].grade > students[j + 1].grade) shouldSwap = true;
            else if (criteria == "name" && students[j].name > students[j + 1].name) shouldSwap = true;
            else if (criteria == "age" && students[j].age > students[j + 1].age) shouldSwap = true;

            if (shouldSwap) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

// Function to measure time for sorting
template <typename Func>
void measureTime(Func sortFunc, Student students[], int size, const string& criteria) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc(students, 0, size - 1, criteria);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Sorting by " << criteria << " took: " << duration.count() << " seconds\n";
}

int main() {
    const int size = 5; // Example dataset size
    Student students[size] = {
        Student("Alice", 90, 20),
        Student("Bob", 85, 22),
        Student("Charlie", 95, 21),
        Student("David", 80, 23),
        Student("Eve", 70, 20)
    };

    int choice, sortChoice;
    string criteria;

    do {
        // Display menu for sorting criteria
        cout << "\nStudent Sorting Menu\n";
        cout << "1. Sort by Grade\n";
        cout << "2. Sort by Name\n";
        cout << "3. Sort by Age\n";
        cout << "4. Exit\n";
        cout << "Select the sorting criteria (1-4): ";
        cin >> choice;

        switch (choice) {
        case 1: criteria = "grade"; break;
        case 2: criteria = "name"; break;
        case 3: criteria = "age"; break;
        case 4: cout << "Exiting...\n"; return 0;
        default: cout << "Invalid choice! Try again.\n"; continue;
        }

        // Sorting algorithm selection
        cout << "\nSelect sorting algorithm:\n";
        cout << "1. Quick Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Bubble Sort\n";
        cout << "Select the sorting algorithm (1-3): ";
        cin >> sortChoice;

        // Copy the students array before sorting
        Student sortedStudents[size];
        copy(students, students + size, sortedStudents);

        switch (sortChoice) {
        case 1:
            measureTime([](Student students[], int low, int high, const string& criteria) { quickSort(students, low, high, criteria); }, sortedStudents, size, criteria);
            break;
        case 2:
            measureTime([](Student students[], int low, int high, const string& criteria) { mergeSort(students, low, high, criteria); }, sortedStudents, size, criteria);
            break;
        case 3:
            bubbleSort(sortedStudents, size, criteria);
            cout << "Bubble Sort results:\n";
            displayStudents(sortedStudents, size);
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (true);

    return 0;
}
