//MSSV: 22520421
//Full Name: Nguyen Thuy Hien
//Classwork1
//Notes or Remarks: ......

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
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

    void printList() { //in danh sách
        if (isEmpty()) {
            cout << "Empty list" << endl;
        }
        else {
            Node* curr = head;
            while (curr != nullptr) {
                cout << curr->data << " ";
                curr = curr->next;
            }
            cout << endl;
        }
    }

    Node* findMiddle() { //tìm node giữa
        if (isEmpty()) return nullptr;
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    bool detectCycle() { //tìm chu kì
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }

    void reverseList() { //đảo danh sách
        Node* prev = nullptr;
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
    }

    void removeDuplicates() { //tìm phần tử giống nhau
        Node* current = head;
        while (current && current->next) {
            if (current->data == current->next->data) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            else {
                current = current->next;
            }
        }
    }

    bool isPalindrome() {
        Node* reversedHead = reverseAndClone(head);
        return isEqual(head, reversedHead);
    }

    Node* reverseAndClone(Node* node) {
        Node* newHead = nullptr;
        while (node) {
            Node* newNode = new Node(node->data);
            newNode->next = newHead;
            newHead = newNode;
            node = node->next;
        }
        return newHead;
    }

    bool isEqual(Node* one, Node* two) {
        while (one && two) {
            if (one->data != two->data) return false;
            one = one->next;
            two = two->next;
        }
        return one == nullptr && two == nullptr;
    }

    void searchValue(int x) {
        Node* curr = head;
        bool found = false;

        cout << "The node value " << x << ": ";
        while (curr != nullptr) {
            if (curr->data == x) {
                found = true;
                cout << curr << " ";
            }
            curr = curr->next;
        }

        if (!found) {
            cout << "NULL";
        }

        cout << endl;
    }

    // Gộp hai danh sách đã sắp xếp
    static LinkedList mergeSorted(LinkedList& l1, LinkedList& l2) {
        LinkedList result;
        Node* p1 = l1.head;
        Node* p2 = l2.head;

        while (p1 && p2) {
            if (p1->data <= p2->data) {
                result.insert(p1->data);
                p1 = p1->next;
            }
            else {
                result.insert(p2->data);
                p2 = p2->next;
            }
        }

        while (p1) {
            result.insert(p1->data);
            p1 = p1->next;
        }

        while (p2) {
            result.insert(p2->data);
            p2 = p2->next;
        }

        return result;
    }

    // Tìm giao điểm của hai danh sách
    static LinkedList findIntersection(LinkedList& l1, LinkedList& l2) {
        LinkedList intersectionList;
        Node* p1 = l1.head;
        Node* p2 = l2.head;

        while (p1 && p2) {
            if (p1->data == p2->data) {
                intersectionList.insert(p1->data);
                p1 = p1->next;
                p2 = p2->next;
            }
            else if (p1->data < p2->data) {
                p1 = p1->next;
            }
            else {
                p2 = p2->next;
            }
        }

        return intersectionList;
    }
};

void menu() {
    cout << "\nChoose option:\n";
    cout << "1. Find middle node of the list\n";
    cout << "2. Detect cycle of the list\n";
    cout << "3. Reverse\n";
    cout << "4. Remove duplicate\n";
    cout << "5. Check palindrome\n";
    cout << "6. Find X value on the list\n";
    cout << "7. Merge two sorted list\n";
    cout << "8. Find the intersection between two list\n";
    cout << "0. Exit\n";
}

int main() {
    LinkedList list1, list2;
    int value;

    // Nhập danh sách thứ nhất
    cout << "Enter first list (End with 0):\n";
    while (true) {
        cin >> value;
        if (value == 0) {
            break;
        }
        list1.insert(value);
    }

    // Nhập danh sách thứ hai
    cout << "Enter second list (End with 0):\n";
    while (true) {
        cin >> value;
        if (value == 0) {
            break;
        }
        list2.insert(value);
    }

    int choice;
    do {
        menu();
        cin >> choice;

        switch (choice) {
        case 1: {
            Node* middle = list1.findMiddle();
            if (middle) {
                cout << "Middle value is: " << middle->data << endl;
            }
            else {
                cout << "Empty list\n";
            }
            break;
        }
        case 2: {
            bool hasCycle = list1.detectCycle();
            cout << (hasCycle ? "List has cycle.\n" : "List does not have cycle.\n");
            break;
        }
        case 3: {
            list1.reverseList();
            cout << "Reverse list: ";
            list1.printList();
            break;
        }
        case 4: {
            list1.removeDuplicates();
            cout << "The list after remove duplicate: ";
            list1.printList();
            break;
        }
        case 5: {
            bool palindrome = list1.isPalindrome();
            cout << (palindrome ? "List is palindrome\n" : "List is not palindrome\n");
            break;
        }
        case 6: {
            int x;
            cout << "Enter X: ";
            cin >> x;
            list1.searchValue(x);
            break;
        }
        case 7: {
            LinkedList mergedList = LinkedList::mergeSorted(list1, list2);
            cout << "Merge list: ";
            mergedList.printList();
            break;
        }
        case 8: {
            LinkedList intersectionList = LinkedList::findIntersection(list1, list2);
            cout << "Intersection between 2 list: ";
            intersectionList.printList();
            break;
        }
        case 0:
            cout << "Exit\n";
            break;
        default:
            cout << "Invalid option\n";
        }
    } while (choice != 0);

    return 0;
}
