#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node (int value){
        data = value;
        next = nullptr;
    }
};
struct Stack{
    Node* top;
    Stack(){
        Node* top = nullptr;
    }
    ~Stack(){
        while(top != nullptr){
            Node* temp = top;
            top = temp-> next;
            delete temp;
        }
    }
    void push(int value){ // Thêm phần tử vào đỉnh Stack
        Node* newNode = new Node(value);
        newNode-> next = top;
        top = newNode;
    }
    int pop() {
        if (top == nullptr) { // Kiểm tra stack rỗng
            cout << "Stack Underflow\n";
            return -1;
        }

        Node* temp = top;       // Lưu nút đỉnh
        int poppedValue = temp->data; // Lấy giá trị của nút đỉnh
        top = temp->next;       // Di chuyển `top` xuống nút tiếp theo
        delete temp;            // Xóa nút đỉnh khỏi bộ nhớ
        return poppedValue;     // Trả về giá trị của nút vừa xóa
}

    int peek(){          // Lấy giá trị phần tử trên đỉnh nhưng không xóa
        if (top == nullptr) { // Kiểm tra stack rỗng
            cout << "Stack empty\n";
            return -1;
        }
        return top->data;     // Trả về giá trị của nút
    }
    bool isEmpty(){       // Kiểm tra Stack rỗng
        if(top==nullptr) return true;
        return false;
    }
};

struct Queue{
    Node* front;
    Node* rear;

    Queue(){
        front = nullptr;
        rear = nullptr;
    }
    ~Queue(){
        while(front!= nullptr){
            Node* temp = front;
            front = temp-> next;
            delete temp;
        }
    }
    void enqueue(int value) // Thêm phần tử vào cuối hàng đợi
    {
        Node* newNode = new Node(value);
        if(front==nullptr){
            front = rear = newNode;
            return;
        }

        rear -> next = newNode;
        rear = newNode;
    }
    int dequeue()           // Lấy và xóa phần tử đầu tiên
    {
        if (front == nullptr){
            cout<<"Queue is empty";
            return -1;
        }

         Node* temp = front;               // Lưu node đầu tiên
        int dequeueValue = temp->data;    // Lấy giá trị của node đầu
        front = temp->next;               // Di chuyển front đến node tiếp theo

        if (front == nullptr) {           // Nếu hàng đợi trở nên rỗng
            rear = nullptr;               // Cập nhật rear về nullptr
        }

        delete temp;                      // Xóa node cũ
        return dequeueValue;              // Trả về giá trị của node bị xóa
    }
    int getFront()        // Lấy giá trị phần tử đầu tiên mà không xóa
    {
        if (front == nullptr){
            cout<<"Queue is empty";
            return -1;
        }
        return front-> data;
    }
    int getRear()           // Lấy giá trị phần tử cuối cùng mà không xóa
    {
        if (front == nullptr){
            cout<<"Queue is empty";
            return -1;
        }
        return rear-> data;
    }
    bool isEmpty()          // Kiểm tra Queue rỗng
    {
        return front == nullptr;
    }
};
