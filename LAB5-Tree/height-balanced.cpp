#include <iostream>
#include <cmath> // For std::abs
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
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

    int height(TreeNode* node) {
        if (!node) return 0;
        return max(height(node->left), height(node->right)) + 1;
    }

    bool isBalanced(TreeNode* node) {
        if (!node) return true;

        // Get the height of left and right subtrees
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        // Check the height difference and recursively check subtrees
        if (abs(leftHeight - rightHeight) > 1) return false;

        return isBalanced(node->left) && isBalanced(node->right);
    }

    void displayIsBalanced() {
        if (isBalanced(root)) {
            cout << "The tree is height-balanced." << endl;
        }
        else {
            cout << "The tree is not height-balanced." << endl;
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
    tree.displayIsBalanced();

    return 0;
}
