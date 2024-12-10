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

class ListNode {
public:
    int value;
    ListNode* next;

    ListNode(int val) : value(val), next(nullptr) {}
};

class List {
public:
    ListNode* head;

    List() : head(nullptr) {}

    void append(int value) {
        ListNode* newNode = new ListNode(value);
        if (!head) {
            head = newNode;
            return;
        }
        ListNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void print() {
        ListNode* temp = head;
        while (temp) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
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

    void levelOrderTraversal(TreeNode* root) {
        if (!root) return;

        Queue q(100); // Custom queue
        q.enqueue(root);

        while (!q.isEmpty()) {
            int levelSize = q.rear - q.front;
            if (levelSize < 0) levelSize += q.capacity; // Handle circular queue wrap-around
            List currentLevel;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.dequeue();
                currentLevel.append(node->value);

                if (node->left) q.enqueue(node->left);
                if (node->right) q.enqueue(node->right);
            }

            // Print values of the current level
            currentLevel.print();
        }
    }

    void displayLevelOrder() {
        cout << "Level-order Traversal (Each Level as Separate List):" << endl;
        levelOrderTraversal(root);
    }

    void inorder(TreeNode* node) {
        if (node) {
            inorder(node->left);
            cout << node->value << " ";
            inorder(node->right);
        }
    }

    void displayInorder() {
        cout << "In-order Traversal: ";
        inorder(root);
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

    tree.displayInorder();
    tree.displayLevelOrder();

    return 0;
}
