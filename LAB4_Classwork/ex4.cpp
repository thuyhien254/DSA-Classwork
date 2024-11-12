#include <iostream>
#include <ctime>
using namespace std;

// Node structure for Linked List
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Insert at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Bubble Sort for Linked List
    void bubbleSort() {
        if (!head) return;
        bool swapped;
        do {
            swapped = false;
            Node* curr = head;
            while (curr && curr->next) {
                if (curr->data > curr->next->data) {
                    swap(curr->data, curr->next->data);
                    swapped = true;
                }
                curr = curr->next;
            }
        } while (swapped);
    }

    // Insertion Sort for Linked List
    void insertionSort() {
        if (!head || !head->next) return;
        Node* sorted = nullptr;
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            if (!sorted || sorted->data >= curr->data) {
                curr->next = sorted;
                sorted = curr;
            }
            else {
                Node* temp = sorted;
                while (temp->next && temp->next->data < curr->data) {
                    temp = temp->next;
                }
                curr->next = temp->next;
                temp->next = curr;
            }
            curr = nextNode;
        }
        head = sorted;
    }

    // Selection Sort for Linked List
    void selectionSort() {
        if (!head) return;
        Node* temp1 = head;
        while (temp1) {
            Node* minNode = temp1;
            Node* temp2 = temp1->next;
            while (temp2) {
                if (temp2->data < minNode->data) {
                    minNode = temp2;
                }
                temp2 = temp2->next;
            }
            if (minNode != temp1) {
                swap(temp1->data, minNode->data);
            }
            temp1 = temp1->next;
        }
    }

    // Function to print the list
    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Measure the time taken by a sorting algorithm
    void measureSortTime(void (LinkedList::* sortFunc)()) {
        clock_t start = clock();
        (this->*sortFunc)();
        clock_t end = clock();
        double duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Time taken for sort: " << duration << " seconds." << endl;
    }
};

// Main function for testing Linked List sorting
int main() {
    LinkedList list;
    list.insert(5);
    list.insert(1);
    list.insert(9);
    list.insert(3);
    list.insert(7);

    cout << "Original list: ";
    list.printList();

    // Test Bubble Sort
    cout << "Testing Bubble Sort" << endl;
    list.measureSortTime(&LinkedList::bubbleSort);
    list.printList();

    // Re-initialize list
    LinkedList list2;
    list2.insert(5);
    list2.insert(1);
    list2.insert(9);
    list2.insert(3);
    list2.insert(7);

    // Test Insertion Sort
    cout << "Testing Insertion Sort" << endl;
    list2.measureSortTime(&LinkedList::insertionSort);
    list2.printList();

    // Re-initialize list
    LinkedList list3;
    list3.insert(5);
    list3.insert(1);
    list3.insert(9);
    list3.insert(3);
    list3.insert(7);

    // Test Selection Sort
    cout << "Testing Selection Sort" << endl;
    list3.measureSortTime(&LinkedList::selectionSort);
    list3.printList();

    return 0;
}
