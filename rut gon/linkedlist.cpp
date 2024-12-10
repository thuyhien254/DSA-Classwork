#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value) { data = value ; next = nullptr;};
};
struct List{
    Node* head;
    List(){ head = nullptr;}

     // 1. Chèn Node vào đầu danh sách
    void insertAtHead(int value){
        Node* newNode = new Node(value);
        newNode-> next = head;
        head = newNode;
    }

    // 2. Chèn Node vào cuối danh sách
    void insertAtTail(int value){
        Node* newNode = new Node(value);
        //neu ko co Node nao thi do la Node cuoi
        if(head == NULL){
            head = newNode;
            return;
        }
        // di toi node cuoi
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp-> next;
        }
        // gan node cuoi vao newNode
        temp -> next = newNode;
    }

    // 3. Xóa Node theo giá trị
    void deleteValue(int value){
        Node* curr = head;
        if(curr->data == value){
            head = curr-> next;
            delete curr;
            return;
        }
        Node* prev = nullptr;
        // di kiem gia tri de xoa
        while(curr-> data != value&&curr!=NULL){
            prev = curr;
            curr = curr-> next;
        }
        // ko tim thay
        if (curr == nullptr) return;
        // xoa nut
        prev->next = curr-> next;
        delete curr;
    }

    // 4. Tìm kiếm giá trị
    bool search(int value){
        Node* curr = head;
        while(curr!= nullptr){
            if(curr-> data ==value){
                return true;
            }
            curr = curr -> next;
        }
        return false;
    }

    // 5. Duyệt danh sách
    void printList(){
        Node* curr = head;
        while (curr != nullptr){
            cout << curr-> data << " ";
            curr = curr-> next;
        }
    }

    // 6. Đảo ngược danh sách
    void reverseList(){
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = curr->next;
        while(curr != nullptr){
            next = curr -> next;
            curr-> next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // 7. Phát hiện chu trình
    bool detectCycle(){
        Node* slow = nullptr;
        Node* fast = head;
        while (fast!= nullptr&&fast-> next!=nullptr){
            slow = slow -> next;
            fast = fast -> next-> next;

            if(slow == fast) return true;
        }
        return false;
    }
};
int main() {
    List list;
    int choice, value;

    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Delete a Value\n";
        cout << "4. Search for a Value\n";
        cout << "5. Print List\n";
        cout << "6. Reverse List\n";
        cout << "7. Detect Cycle\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at head: ";
            cin >> value;
            list.insertAtHead(value);
            break;
        case 2:
            cout << "Enter value to insert at tail: ";
            cin >> value;
            list.insertAtTail(value);
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteValue(value);
            break;
        case 4:
            cout << "Enter value to search: ";
            cin >> value;
            cout << (list.search(value) ? "Found" : "Not Found") << endl;
            break;
        case 5:
            list.printList();
            break;
        case 6:
            list.reverseList();
            cout << "List reversed.\n";
            break;
        case 7:
            cout << (list.detectCycle() ? "Cycle Detected" : "No Cycle") << endl;
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

