#include <iostream>
#include <algorithm>
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

    int calculateDiameter(TreeNode* node, int& diameter) {
        if (!node) return 0;

        // Compute the height of left and right subtrees
        int leftHeight = calculateDiameter(node->left, diameter);
        int rightHeight = calculateDiameter(node->right, diameter);

        // Update the diameter if the path through this node is longer
        diameter = max(diameter, leftHeight + rightHeight);

        // Return the height of the current node
        return max(leftHeight, rightHeight) + 1;
    }

    int getDiameter() {
        int diameter = 0;
        calculateDiameter(root, diameter);
        return diameter;
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
    cout << "Diameter of the tree: " << tree.getDiameter() << endl;

    return 0;
}
