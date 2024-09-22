﻿#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* random;

    Node(int val) {
        data = val;
        next = nullptr;
        random = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int data) {
        if (data == 0) {
            return;
        }
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void printList(bool showRandom = false) {
        if (isEmpty()) {
            cout << "Empty list" << endl;
        }
        else {
            Node* curr = head;
            while (curr != nullptr) {
                cout << curr->data;
                if (showRandom) {
                    if (curr->random) {
                        cout << ", Random points to: " << curr->random->data;
                    }
                    else {
                        cout << ", Random points to: nullptr";
                    }
                }
                cout << endl;
                curr = curr->next;
            }
        }
    }

    void addTwoNumb() {
        int value1, value2;
        cout << "Enter first number: ";
        cin >> value1;
        insert(value1);

        cout << "Enter second number: ";
        cin >> value2;
        insert(value2);
    }

    void setRandom() {
        if (head && head->next) {
            head->random = head->next;
            head->next->random = head;
        }
    }

    void swapNodes(int x, int y) {
        if (x == y) return;

        Node* prevX = nullptr, * currX = head;
        while (currX && currX->data != x) {
            prevX = currX;
            currX = currX->next;
        }

        Node* prevY = nullptr, * currY = head;
        while (currY && currY->data != y) {
            prevY = currY;
            currY = currY->next;
        }

        if (!currX || !currY) return;

        if (prevX == nullptr) {
            head = currY;
        }
        else {
            prevX->next = currY;
        }

        if (prevY == nullptr) {
            head = currX;
        }
        else {
            prevY->next = currX;
        }

        Node* temp = currX->next;
        currX->next = currY->next;
        currY->next = temp;
    }

    void removeNthFromEnd(int n) {
        Node* first = head;
        Node* second = head;

        for (int i = 0; i < n; i++) {
            if (first == nullptr) return;
            first = first->next;
        }

        if (first == nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* prev = nullptr;
        while (first && first->next) {
            first = first->next;
            prev = second;
            second = second->next;
        }

        if (prev == nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            prev->next = second->next;
            delete second;
        }
    }

    void separateOddEven() {
        if (head == nullptr) return;

        Node* odd = nullptr, * even = nullptr;
        Node* oddTail = nullptr, * evenTail = nullptr;
        Node* curr = head;

        while (curr) {
            if (curr->data % 2 != 0) {
                if (!odd) {
                    odd = oddTail = curr;
                }
                else {
                    oddTail->next = curr;
                    oddTail = oddTail->next;
                }
            }
            else {
                if (!even) {
                    even = evenTail = curr;
                }
                else {
                    evenTail->next = curr;
                    evenTail = evenTail->next;
                }
            }
            curr = curr->next;
        }

        if (oddTail) oddTail->next = even;
        if (evenTail) evenTail->next = nullptr;

        head = odd ? odd : even;
    }

    void divideIntoParts(int k) {
        Node* current = head;
        int length = 0;

        while (current) {
            length++;
            current = current->next;
        }

        int partSize = length / k;
        int remainder = length % k;

        current = head;
        for (int i = 0; i < k; ++i) {
            cout << "Part " << i + 1 << ": ";
            for (int j = 0; j < partSize + (i < remainder ? 1 : 0); ++j) {
                if (current) {
                    cout << current->data << " ";
                    current = current->next;
                }
            }
            cout << endl;
        }
    }

    void removeZeroSumConsecutiveNodes() {
        Node* current = head;

        while (current) {
            Node* runner = current;
            int sum = 0;

            while (runner) {
                sum += runner->data;
                if (sum == 0) {
                    Node* temp = current;
                    while (temp != runner) {
                        Node* nextNode = temp->next;
                        delete temp;
                        temp = nextNode;
                    }
                    if (current == head) {
                        head = runner->next;
                    }
                    else {
                        Node* prev = head;
                        while (prev->next != current) {
                            prev = prev->next;
                        }
                        prev->next = runner->next;
                    }
                    current = runner->next;
                    break;
                }
                runner = runner->next;
            }

            if (runner == nullptr) {
                current = current->next;
            }
        }
    }

    void automaticInput() {
        srand(time(0));
        int numberOfEntries = rand() % 21 + 39; // Random number of entries [39; 59]

        for (int i = 0; i < numberOfEntries; ++i) {
            int randomValue = rand() % 199 - 99; // Value in range [-99, 99]
            insert(randomValue);
        }
    }
};

// Menu
void menu() {
    cout << "\nChoose option:\n";
    cout << "1. Add two numbers to the list\n";
    cout << "2. Print original list\n";
    cout << "3. Swap two nodes\n";
    cout << "4. Remove from end\n";
    cout << "5. Separate odd and even\n";
    cout << "6. Divide List into Parts\n";
    cout << "7. Remove Zero-Sum Consecutive Nodes\n";
    cout << "8. Automatically input random values\n";
    cout << "0. Exit\n";
}

int main() {
    LinkedList list;
    int choice;

    cout << "Manual input from keyboard:\n";
    int value;
    cout << "Enter list (End with 0):\n";
    while (true) {
        cin >> value;
        if (value == 0) {
            break;
        }
        list.insert(value);
    }

    do {
        menu();
        cin >> choice;

        switch (choice) {
        case 1:
            list.addTwoNumb();
            cout << "List after adding 2 numbers:\n";
            list.printList();
            break;
        case 2:
            cout << "Original list:\n";
            list.printList();
            break;
        case 3: {
            int x, y;
            cout << "Enter two values to swap: ";
            cin >> x >> y;
            list.swapNodes(x, y);
            cout << "List after swapping " << x << " and " << y << ":\n";
            list.printList(false);
            break;
        }
        case 4: {
            int n;
            cout << "Enter the position (from the end) of the node to remove: ";
            cin >> n;
            list.removeNthFromEnd(n);
            cout << "List after removing the " << n << "-th node from the end:\n";
            list.printList();
            break;
        }
        case 5:
            list.separateOddEven();
            cout << "List after separating odd and even:\n";
            list.printList();
            break;
        case 6: {
            int k;
            cout << "Enter number of parts to divide the list into: ";
            cin >> k;
            list.divideIntoParts(k);
            break;
        }
        case 7:
            list.removeZeroSumConsecutiveNodes();
            cout << "List after removing zero-sum consecutive nodes:\n";
            list.printList();
            break;
        case 8:
            list.automaticInput();
            cout << "List after automatically inputting random values:\n";
            list.printList();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
