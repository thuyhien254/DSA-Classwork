#include <iostream>
#include <cmath>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    TreeNode* root;

    BinarySearchTree() : root(nullptr) {}

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

    TreeNode* findMin(TreeNode* node) {
        if (!node) return nullptr;
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    TreeNode* findMax(TreeNode* node) {
        if (!node) return nullptr;
        while (node->right) {
            node = node->right;
        }
        return node;
    }

    bool isBalanced(TreeNode* node) {
        if (!node) return true;

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        if (abs(leftHeight - rightHeight) > 1) {
            return false;
        }

        return isBalanced(node->left) && isBalanced(node->right);
    }

    int height(TreeNode* node) {
        if (!node) return 0;

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        return max(leftHeight, rightHeight) + 1;
    }

    void displayMin() {
        TreeNode* minNode = findMin(root);
        if (minNode) {
            cout << "Minimum value: " << minNode->value << endl;
        }
        else {
            cout << "The tree is empty." << endl;
        }
    }

    void displayMax() {
        TreeNode* maxNode = findMax(root);
        if (maxNode) {
            cout << "Maximum value: " << maxNode->value << endl;
        }
        else {
            cout << "The tree is empty." << endl;
        }
    }

    void displayHeight() {
        cout << "Height of the tree: " << height(root) << endl;
    }

    void displayIsBalanced() {
        if (isBalanced(root)) {
            cout << "The tree is balanced." << endl;
        }
        else {
            cout << "The tree is not balanced." << endl;
        }
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
    BinarySearchTree bst;
    int n, value;

    cout << "Enter the number of values to insert: ";
    cin >> n;

    cout << "Enter the values to insert into the tree: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        bst.insert(value);
    }

    bst.displayInorder();
    bst.displayMin();
    bst.displayMax();
    bst.displayHeight();
    bst.displayIsBalanced();

    return 0;
}
