#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
using namespace std;

// Music Track structure to represent a song
struct Song {
    string title;    // Song title
    string artist;   // Song artist
    string genre;    // Genre of the song
    string mood;     // Mood of the song
    int duration;    // Duration of the song in seconds

    // Default constructor
    Song() : title(""), artist(""), genre(""), mood(""), duration(0) {}

    // Parameterized constructor
    Song(string t, string a, string g, string m, int d) : title(t), artist(a), genre(g), mood(m), duration(d) {}
};

// Function to display the playlist
void displayPlaylist(Song songs[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Title: " << songs[i].title << ", Artist: " << songs[i].artist
            << ", Genre: " << songs[i].genre << ", Mood: " << songs[i].mood
            << ", Duration: " << songs[i].duration << " seconds\n";
    }
    cout << "---------------------------\n";
}

// Quick Sort function
int partition(Song songs[], int low, int high, const string& criteria) {
    Song pivot = songs[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        bool shouldSwap = false;
        if (criteria == "title" && songs[j].title < pivot.title) shouldSwap = true;
        else if (criteria == "artist" && songs[j].artist < pivot.artist) shouldSwap = true;
        else if (criteria == "genre" && songs[j].genre < pivot.genre) shouldSwap = true;
        else if (criteria == "mood" && songs[j].mood < pivot.mood) shouldSwap = true;
        else if (criteria == "duration" && songs[j].duration < pivot.duration) shouldSwap = true;

        if (shouldSwap) {
            ++i;
            swap(songs[i], songs[j]);
        }
    }

    swap(songs[i + 1], songs[high]);
    return i + 1;
}

void quickSort(Song songs[], int low, int high, const string& criteria) {
    if (low < high) {
        int pi = partition(songs, low, high, criteria);
        quickSort(songs, low, pi - 1, criteria);
        quickSort(songs, pi + 1, high, criteria);
    }
}

// Merge Sort function
void merge(Song songs[], int l, int m, int r, const string& criteria) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Song* L = new Song[n1];
    Song* R = new Song[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = songs[l + i];
    for (int i = 0; i < n2; ++i)
        R[i] = songs[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        bool shouldSwap = false;
        if (criteria == "title" && L[i].title <= R[j].title) shouldSwap = true;
        else if (criteria == "artist" && L[i].artist <= R[j].artist) shouldSwap = true;
        else if (criteria == "genre" && L[i].genre <= R[j].genre) shouldSwap = true;
        else if (criteria == "mood" && L[i].mood <= R[j].mood) shouldSwap = true;
        else if (criteria == "duration" && L[i].duration <= R[j].duration) shouldSwap = true;

        if (shouldSwap) {
            songs[k] = L[i];
            ++i;
        }
        else {
            songs[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        songs[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        songs[k] = R[j];
        ++j;
        ++k;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(Song songs[], int l, int r, const string& criteria) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(songs, l, m, criteria);
        mergeSort(songs, m + 1, r, criteria);
        merge(songs, l, m, r, criteria);
    }
}

// Bubble Sort function
void bubbleSort(Song songs[], int size, const string& criteria) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            bool shouldSwap = false;
            if (criteria == "title" && songs[j].title > songs[j + 1].title) shouldSwap = true;
            else if (criteria == "artist" && songs[j].artist > songs[j + 1].artist) shouldSwap = true;
            else if (criteria == "genre" && songs[j].genre > songs[j + 1].genre) shouldSwap = true;
            else if (criteria == "mood" && songs[j].mood > songs[j + 1].mood) shouldSwap = true;
            else if (criteria == "duration" && songs[j].duration > songs[j + 1].duration) shouldSwap = true;

            if (shouldSwap) {
                swap(songs[j], songs[j + 1]);
            }
        }
    }
}

// Function to measure time for sorting
template <typename Func>
void measureTime(Func sortFunc, Song songs[], int size, const string& criteria) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc(songs, 0, size - 1, criteria);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Sorting by " << criteria << " took: " << duration.count() << " seconds\n";
}

int main() {
    const int size = 5; // Example dataset size
    Song songs[size] = {
        Song("Shape of You", "Ed Sheeran", "Pop", "Happy", 240),
        Song("Blinding Lights", "The Weeknd", "Pop", "Energetic", 200),
        Song("Rockstar", "Post Malone", "Hip-hop", "Sad", 300),
        Song("Happier", "Marshmello", "Pop", "Melancholic", 210),
        Song("Dance Monkey", "Tones and I", "Pop", "Happy", 210)
    };

    int choice, sortChoice;
    string criteria;

    do {
        // Display menu for sorting criteria
        cout << "\nMusic Sorting Menu\n";
        cout << "1. Sort by Title\n";
        cout << "2. Sort by Artist\n";
        cout << "3. Sort by Genre\n";
        cout << "4. Sort by Mood\n";
        cout << "5. Sort by Duration\n";
        cout << "6. Exit\n";
        cout << "Select the sorting criteria (1-6): ";
        cin >> choice;

        switch (choice) {
        case 1: criteria = "title"; break;
        case 2: criteria = "artist"; break;
        case 3: criteria = "genre"; break;
        case 4: criteria = "mood"; break;
        case 5: criteria = "duration"; break;
        case 6: cout << "Exiting...\n"; return 0;
        default: cout << "Invalid choice! Try again.\n"; continue;
        }

        // Sorting algorithm selection
        cout << "\nSelect sorting algorithm:\n";
        cout << "1. Quick Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Bubble Sort\n";
        cout << "Select the sorting algorithm (1-3): ";
        cin >> sortChoice;

        // Copy the songs array before sorting
        Song sortedSongs[size];
        copy(songs, songs + size, sortedSongs);

        switch (sortChoice) {
        case 1:
            measureTime([](Song songs[], int low, int high, const string& criteria) { quickSort(songs, low, high, criteria); }, sortedSongs, size, criteria);
            break;
        case 2:
            measureTime([](Song songs[], int low, int high, const string& criteria) { mergeSort(songs, low, high, criteria); }, sortedSongs, size, criteria);
            break;
        case 3:
            bubbleSort(sortedSongs, size, criteria);
            displayPlaylist(sortedSongs, size);
            break;
        default:
            cout << "Invalid choice! Try again.\n"; break;
        }

        // Display sorted playlist
        displayPlaylist(sortedSongs, size);

    } while (true);

    return 0;
}
