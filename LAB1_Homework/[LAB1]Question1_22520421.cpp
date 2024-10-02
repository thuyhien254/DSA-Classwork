#include <iostream>

using namespace std;

struct Song {
    char name[101];
    Song* next;
    Song* prev;

    Song() {
        next = prev = nullptr;
        for (int i = 0; i < 101; ++i) name[i] = '\0'; // Initialize name
    }

    void setName(char* songName) {
        int i = 0;
        while (songName[i] != '\0' && i < 100) {
            name[i] = songName[i];
            ++i;
        }
        name[i] = '\0'; // Ensure null termination
    }
};

class Playlist {
private:
    Song* head;
    Song* current;

public:
    Playlist() {
        head = nullptr;
        current = nullptr;
    }

    void addSong(char* songName) {
        Song* newSong = new Song();
        newSong->setName(songName);

        if (!head) {
            head = newSong;
            current = head;
            head->next = head;
            head->prev = head;
        }
        else {
            Song* last = head->prev;
            last->next = newSong;
            newSong->prev = last;
            newSong->next = head;
            head->prev = newSong;
        }
    }

    void playNext() {
        if (current) current = current->next;
    }

    void playPrevious() {
        if (current) current = current->prev;
    }

    void removeSong(char* songName) {
        if (!head) return;

        Song* temp = head;
        do {
            int i = 0;
            while (temp->name[i] == songName[i] && temp->name[i] != '\0' && songName[i] != '\0') ++i;

            if (temp->name[i] == '\0' && songName[i] == '\0') {
                if (temp == head && head->next == head) {
                    delete temp;
                    head = current = nullptr;
                    return;
                }

                if (temp == head) head = head->next;
                if (temp == current) current = current->next;

                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                delete temp;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void displayPlaylist() {
        if (!head) {
            cout << endl; // Display nothing if the playlist is empty
            return;
        }

        Song* temp = head;
        do {
            cout << temp->name << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;  // Read the number of operations
    Playlist playlist;

    for (int i = 0; i < n; ++i) {
        char operation[10];
        cin >> operation;

        if (operation[0] == 'A') {  // ADD
            char songName[101];
            cin >> songName;
            playlist.addSong(songName);

        }
        else if (operation[0] == 'N') {  // NEXT
            playlist.playNext();

        }
        else if (operation[0] == 'P') {  // PREV
            playlist.playPrevious();

        }
        else if (operation[0] == 'R') {  // REMOVE
            char songName[101];
            cin >> songName;
            playlist.removeSong(songName);

        }
        else if (operation[0] == 'D') {  // DISPLAY
            playlist.displayPlaylist();
        }
    }

    return 0;
}
