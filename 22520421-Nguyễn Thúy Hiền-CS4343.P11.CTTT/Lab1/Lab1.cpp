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

    void printList() {
        if (isEmpty()) {
            cout << "Danh sach rong." << endl;
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

    Node* findMiddle() {
        if (isEmpty()) return nullptr;
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    bool detectCycle() {
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }

    void reverseList() {
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

    void removeDuplicates() {
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

        cout << "Cac dia chi cua cac node co gia tri " << x << ": ";
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
    cout << "\nChon chuc nang:\n";
    cout << "1. Tim nut giua cua danh sach\n";
    cout << "2. Phat hien chu ky trong danh sach\n";
    cout << "3. Dao nguoc danh sach\n";
    cout << "4. Loai bo phan tu trung lap\n";
    cout << "5. Kiem tra danh sach co phai la palindrome\n";
    cout << "6. Tim cac nut co gia tri X trong danh sach\n";
    cout << "7. Gop hai danh sach da sap xep\n";
    cout << "8. Tim giao diem cua hai danh sach\n";
    cout << "0. Thoat\n";
}

int main() {
    LinkedList list1, list2;
    int value;

    // Nhập danh sách thứ nhất
    cout << "Nhap cac phan tu cua danh sach thu nhat (Nhap 0 de ket thuc):\n";
    while (true) {
        cin >> value;
        if (value == 0) {
            break;
        }
        list1.insert(value);
    }

    // Nhập danh sách thứ hai
    cout << "Nhap cac phan tu cua danh sach thu hai (Nhap 0 de ket thuc):\n";
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
                cout << "Gia tri o giua danh sach la: " << middle->data << endl;
            }
            else {
                cout << "Danh sach rong.\n";
            }
            break;
        }
        case 2: {
            bool hasCycle = list1.detectCycle();
            cout << (hasCycle ? "Danh sach co chu ky.\n" : "Danh sach khong co chu ky.\n");
            break;
        }
        case 3: {
            list1.reverseList();
            cout << "Danh sach sau khi dao nguoc: ";
            list1.printList();
            break;
        }
        case 4: {
            list1.removeDuplicates();
            cout << "Danh sach sau khi loai bo phan tu trung lap: ";
            list1.printList();
            break;
        }
        case 5: {
            bool palindrome = list1.isPalindrome();
            cout << (palindrome ? "Danh sach la palindrome.\n" : "Danh sach khong phai la palindrome.\n");
            break;
        }
        case 6: {
            int x;
            cout << "Nhap gia tri X can tim: ";
            cin >> x;
            list1.searchValue(x);
            break;
        }
        case 7: {
            LinkedList mergedList = LinkedList::mergeSorted(list1, list2);
            cout << "Danh sach sau khi gop: ";
            mergedList.printList();
            break;
        }
        case 8: {
            LinkedList intersectionList = LinkedList::findIntersection(list1, list2);
            cout << "Giao diem cua hai danh sach: ";
            intersectionList.printList();
            break;
        }
        case 0:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    } while (choice != 0);

    return 0;
}
