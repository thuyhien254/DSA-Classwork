//MSSV:22520421
//Full Name: Nguyen Thuy Hien
//Classwork1
//Notes or Remarks: ......
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    int stackTop;
    int maxSize;
    int* stackArray;
public:
    // Constructor to initialize the stack
    Stack(int size) {
        maxSize = size;
        stackArray = new int[maxSize];
        stackTop = -1;
    }
    ~Stack() {
        delete[] stackArray;
    }

    // Check empty
    bool isEmpty() {
        return stackTop == -1;
    }

    // Check full
    bool isFull() {
        return stackTop == maxSize - 1;
    }

    // Push an element onto the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow!" << endl;
        }
        else {
            stackArray[++stackTop] = value;
            cout << "Pushed " << value << " onto the stack." << endl;
        }
    }

    // Pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return -1;  
        }
        else {
            return stackArray[stackTop--];
        }
    }

    // Print the top element of the stack
    void printTop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        }
        else {
            cout << "Top element: " << stackArray[stackTop] << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack stack(size);
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Initialize stack\n";
        cout << "2. Check if stack is empty\n";
        cout << "3. Check if stack is full\n";
        cout << "4. Push element onto stack\n";
        cout << "5. Pop element from stack\n";
        cout << "6. Print top element\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            stack = Stack(size);  // Reinitialize the stack
            cout << "Stack initialized." << endl;
            break;
        case 2:
            if (stack.isEmpty())
                cout << "Stack is empty." << endl;
            else
                cout << "Stack is not empty." << endl;
            break;
        case 3:
            if (stack.isFull())
                cout << "Stack is full." << endl;
            else
                cout << "Stack is not full." << endl;
            break;
        case 4:
            cout << "Enter value to push: ";
            cin >> value;
            stack.push(value);
            break;
        case 5:
            value = stack.pop();
            if (value != -1)
                cout << "Popped element: " << value << endl;
            break;
        case 6:
            stack.printTop();
            break;
        case 7:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}