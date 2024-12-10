#include <iostream>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class QueueNode {
public:
    TreeNode* node;
    int hd; // Horizontal distance
    QueueNode* next;

    QueueNode(TreeNode* n, int distance) : node(n), hd(distance), next(nullptr) {}
};

class Queue {
public:
    QueueNode* front;
    QueueNode* rear;

    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(TreeNode* node, int hd) {
        QueueNode* newNode = new QueueNode(node, hd);
        if (!rear) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    QueueNode* dequeue() {
        if (!front) return nullptr;
        QueueNode* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        return temp;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

class VerticalNode {
public:
    int value;
    VerticalNode* next;

    VerticalNode(int val) : value(val), next(nullptr) {}
};

class VerticalOrderMap {
public:
    VerticalNode* nodes[200]; // Array for -100 to +100 horizontal distances
    int offset;

    VerticalOrderMap() : offset(100) {
        for (int i = 0; i < 200; i++) {
            nodes[i] = nullptr;
        }
    }

    void add(int hd, int value) {
        int index = hd + offset;
        VerticalNode* newNode = new VerticalNode(value);
        if (!nodes[index]) {
            nodes[index] = newNode;
        }
        else {
            VerticalNode* temp = nodes[index];
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void print() {
        for (int i = 0; i < 200; i++) {
            if (nodes[i]) {
                VerticalNode* temp = nodes[i];
                cout << "Vertical Slice " << (i - offset) << ": ";
                while (temp) {
                    cout << temp->value << " ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
    }
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    TreeNode* insert(TreeNode* node, int value) {
        if (!node) return new TreeNode(value);
        if (value < node->value) {
            node->left = insert(node->left, value);
        }
        else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void verticalOrderTraversal() {
        if (!root) return;

        Queue q;
        VerticalOrderMap vmap;

        q.enqueue(root, 0);

        while (!q.isEmpty()) {
            QueueNode* qnode = q.dequeue();
            TreeNode* current = qnode->node;
            int hd = qnode->hd;
            delete qnode;

            vmap.add(hd, current->value);

            if (current->left) {
                q.enqueue(current->left, hd - 1);
            }
            if (current->right) {
                q.enqueue(current->right, hd + 1);
            }
        }

        vmap.print();
    }
};

int main() {
    BinaryTree tree;
    int n, value;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the values to insert into the tree: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        tree.insert(value);
    }

    cout << "Vertical Order Traversal:" << endl;
    tree.verticalOrderTraversal();

    return 0;
}
