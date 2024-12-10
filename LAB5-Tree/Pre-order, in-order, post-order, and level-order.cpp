#include <iostream>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class Queue {
public:
    TreeNode** arr;
    int front, rear, capacity;

    Queue(int size) {
        capacity = size;
        arr = new TreeNode * [capacity];
        front = 0;
        rear = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    void enqueue(TreeNode* node) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue.\n";
            return;
        }
        arr[rear] = node;
        rear = (rear + 1) % capacity;
    }

    TreeNode* dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue.\n";
            return nullptr;
        }
        TreeNode* node = arr[front];
        front = (front + 1) % capacity;
        return node;
    }
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    TreeNode* insert(TreeNode* node, int value) {
        if (!node) {
            return new TreeNode(value);
        }
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

    void preorder(TreeNode* node) {
        if (node) {
            cout << node->value << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void inorder(TreeNode* node) {
        if (node) {
            inorder(node->left);
            cout << node->value << " ";
            inorder(node->right);
        }
    }

    void postorder(TreeNode* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->value << " ";
        }
    }

    void levelorder(TreeNode* node) {
        if (!node) return;

        Queue q(100);  // Initialize a queue with sufficient size
        q.enqueue(node);

        while (!q.isEmpty()) {
            TreeNode* current = q.dequeue();
            cout << current->value << " ";

            if (current->left) q.enqueue(current->left);
            if (current->right) q.enqueue(current->right);
        }
    }

    void displayPreorder() {
        cout << "Pre-order Traversal: ";
        preorder(root);
        cout << endl;
    }

    void displayInorder() {
        cout << "In-order Traversal: ";
        inorder(root);
        cout << endl;
    }

    void displayPostorder() {
        cout << "Post-order Traversal: ";
        postorder(root);
        cout << endl;
    }

    void displayLevelorder() {
        cout << "Level-order Traversal: ";
        levelorder(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    int n, value;

    cout << "Enter the number of values to insert: ";
    cin >> n;

    cout << "Enter the values to insert into the tree: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        tree.insert(value);
    }

    tree.displayPreorder();
    tree.displayInorder();
    tree.displayPostorder();
    tree.displayLevelorder();

    return 0;
}
