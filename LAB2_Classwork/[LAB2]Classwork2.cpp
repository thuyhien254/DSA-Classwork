//MSSV:22520421
//Full Name: Nguyen Thuy Hien
//Classwork2
//Notes or Remarks: ......
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
   int* queueArray;
    int front;
    int rear;
    int maxSize;

public:
    Queue(int size) {
        maxSize = size;
        queueArray = new int[maxSize];
        front = -1;
        rear = -1;
    }

    ~Queue() {
        delete[] queueArray;
    }

    // Check empty
    bool isEmpty() {
        return front == -1;
    }

    // Check full
    bool isFull() {
        return (rear + 1) % maxSize == front; // Circular queue condition
    }

    // Enqueue 
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue overflow"<< endl;
        }
        else {
            if (isEmpty()) {
                front = 0; 
            }
            rear = (rear + 1) % maxSize; // Circular increment
            queueArray[rear] = value;
            cout << "Enqueued " << value << " into the queue." << endl;
        }
    }
    // Dequeue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow" << endl;
            return -1;
        }
        else {
            int value = queueArray[front];
            if (front == rear) { 
                rear = -1;
            }
            else {
                front = (front + 1) % maxSize; // Circular increment
            }
            return value;
        }
    }
    // Print the front
    void printFront() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        }
        else {
            cout << "Front element: " << queueArray[front] << endl;
        }
    }

    // Print the rear
    void printRear() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        }
        else {
            cout << "Rear element: " << queueArray[rear] << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue queue(size);
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Check if queue is empty\n";
        cout << "2. Check if queue is full\n";
        cout << "3. Enqueue element into queue\n";
        cout << "4. Dequeue element from queue\n";
        cout << "5. Print front and rear elements\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (queue.isEmpty())
                cout << "Queue is empty." << endl;
            else
                cout << "Queue is not empty." << endl;
            break;
        case 2:
            if (queue.isFull())
                cout << "Queue is full." << endl;
            else
                cout << "Queue is not full." << endl;
            break;
        case 3:
            cout << "Enter value to enqueue: ";
            cin >> value;
            queue.enqueue(value);
            break;
        case 4:
            value = queue.dequeue();
            if (value != -1)
                cout << "Dequeued element: " << value << endl;
            break;
        case 5:
            queue.printFront();
            queue.printRear();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 6);

    return 0;
}
