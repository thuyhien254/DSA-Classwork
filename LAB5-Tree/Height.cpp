#include <iostream>
#include <algorithm> // For std::max
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
        if (!node) return 0; // Base case: height of an empty tree is 0
        return max(height(node->left), height(node->right)) + 1;
    }

    void displayHeight() {
        cout << "Height of the tree: " << height(root) << endl;
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
    tree.displayHeight();

    return 0;
}
