#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>

using namespace std;

// Define a structure to represent a social media post
struct Post {
    string content;    // Content of the post
    int likes;         // Number of likes
    int shares;        // Number of shares
    int comments;      // Number of comments
    string timestamp;  // Time when the post was created

    // Default constructor to initialize with default values
    Post() : content(""), likes(0), shares(0), comments(0), timestamp("") {}

    // Constructor to initialize the Post with all values
    Post(string c, int l, int s, int com, string t)
        : content(c), likes(l), shares(s), comments(com), timestamp(t) {
    }
};

// Function to display posts
void displayPosts(Post posts[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Content: " << posts[i].content << endl;
        cout << "Likes: " << posts[i].likes << ", Shares: " << posts[i].shares << ", Comments: " << posts[i].comments << ", Time: " << posts[i].timestamp << endl;
        cout << "---------------------------------" << endl;
    }
}

// Quick Sort function
int partition(Post posts[], int low, int high, const string& criteria) {
    Post pivot = posts[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        bool shouldSwap = false;
        if (criteria == "likes" && posts[j].likes < pivot.likes) shouldSwap = true;
        else if (criteria == "shares" && posts[j].shares < pivot.shares) shouldSwap = true;
        else if (criteria == "comments" && posts[j].comments < pivot.comments) shouldSwap = true;
        else if (criteria == "time" && posts[j].timestamp < pivot.timestamp) shouldSwap = true;

        if (shouldSwap) {
            ++i;
            swap(posts[i], posts[j]);
        }
    }

    swap(posts[i + 1], posts[high]);
    return i + 1;
}

void quickSort(Post posts[], int low, int high, const string& criteria) {
    if (low < high) {
        int pi = partition(posts, low, high, criteria);
        quickSort(posts, low, pi - 1, criteria);
        quickSort(posts, pi + 1, high, criteria);
    }
}

// Merge Sort functions
void merge(Post posts[], int l, int m, int r, const string& criteria) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Post* L = new Post[n1]; // Allocate memory for left subarray
    Post* R = new Post[n2]; // Allocate memory for right subarray

    for (int i = 0; i < n1; ++i)
        L[i] = posts[l + i];
    for (int i = 0; i < n2; ++i)
        R[i] = posts[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        bool shouldSwap = false;
        if (criteria == "likes" && L[i].likes <= R[j].likes) shouldSwap = true;
        else if (criteria == "shares" && L[i].shares <= R[j].shares) shouldSwap = true;
        else if (criteria == "comments" && L[i].comments <= R[j].comments) shouldSwap = true;
        else if (criteria == "time" && L[i].timestamp <= R[j].timestamp) shouldSwap = true;

        if (shouldSwap) {
            posts[k] = L[i];
            ++i;
        }
        else {
            posts[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        posts[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        posts[k] = R[j];
        ++j;
        ++k;
    }

    delete[] L; // Free allocated memory
    delete[] R; // Free allocated memory
}

void mergeSort(Post posts[], int l, int r, const string& criteria) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(posts, l, m, criteria);
        mergeSort(posts, m + 1, r, criteria);
        merge(posts, l, m, r, criteria);
    }
}

// Bubble Sort function
void bubbleSort(Post posts[], int size, const string& criteria) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            bool shouldSwap = false;
            if (criteria == "likes" && posts[j].likes > posts[j + 1].likes) shouldSwap = true;
            else if (criteria == "shares" && posts[j].shares > posts[j + 1].shares) shouldSwap = true;
            else if (criteria == "comments" && posts[j].comments > posts[j + 1].comments) shouldSwap = true;
            else if (criteria == "time" && posts[j].timestamp > posts[j + 1].timestamp) shouldSwap = true;

            if (shouldSwap) {
                swap(posts[j], posts[j + 1]);
            }
        }
    }
}

// Function to measure the time taken for sorting
template <typename Func>
void measureTime(Func sortFunc, Post posts[], int size, const string& criteria) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc(posts, 0, size - 1, criteria);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Sorting by " << criteria << " took: " << duration.count() << " seconds" << endl;
}

int main() {
    const int size = 5; // Number of posts
    Post posts[size] = {
        Post("Post 1", 150, 50, 30, "2024-11-01 10:00"),
        Post("Post 2", 200, 100, 80, "2024-11-02 11:00"),
        Post("Post 3", 120, 60, 40, "2024-10-30 09:00"),
        Post("Post 4", 180, 80, 60, "2024-11-05 13:00"),
        Post("Post 5", 220, 90, 50, "2024-11-03 12:00")
    };

    int choice, sortChoice;
    string criteria;

    do {
        cout << "Social Media Feed Sorting" << endl;
        cout << "1. Sort by Likes" << endl;
        cout << "2. Sort by Shares" << endl;
        cout << "3. Sort by Comments" << endl;
        cout << "4. Sort by Time" << endl;
        cout << "5. Exit" << endl;
        cout << "Select the sorting criteria (1-4): ";
        cin >> choice;

        switch (choice) {
        case 1: criteria = "likes"; break;
        case 2: criteria = "shares"; break;
        case 3: criteria = "comments"; break;
        case 4: criteria = "time"; break;
        default: cout << "Invalid choice!" << endl; continue;
        }

        // Sorting algorithm selection
        cout << "\nSelect sorting algorithm:" << endl;
        cout << "1. Quick Sort" << endl;
        cout << "2. Merge Sort" << endl;
        cout << "3. Bubble Sort" << endl;
        cout << "Select the sorting algorithm (1-3): ";
        cin >> sortChoice;

        Post sortedPosts[size];
        copy(posts, posts + size, sortedPosts);

        switch (sortChoice) {
        case 1:
            measureTime([](Post posts[], int low, int high, const string& criteria) { quickSort(posts, low, high, criteria); }, sortedPosts, size, criteria);
            break;
        case 2:
            measureTime([](Post posts[], int low, int high, const string& criteria) { mergeSort(posts, low, high, criteria); }, sortedPosts, size, criteria);
            break;
        case 3:
            measureTime([](Post posts[], int low, int high, const string& criteria) { bubbleSort(posts, high, criteria); }, sortedPosts, size, criteria);
            break;
        default:
            cout << "Invalid sorting algorithm!" << endl;
            continue;
        }

        displayPosts(sortedPosts, size);

    } while (true);

    return 0;
}
