#include <iostream>
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

    TreeNode* findLCA(TreeNode* node, int p, int q) {
        if (!node) return nullptr;

        // If both p and q are smaller than node's value, LCA lies in the left subtree
        if (p < node->value && q < node->value) {
            return findLCA(node->left, p, q);
        }

        // If both p and q are greater than node's value, LCA lies in the right subtree
        if (p > node->value && q > node->value) {
            return findLCA(node->right, p, q);
        }

        // If one of p or q is on one side and the other is on the opposite side,
        // then the current node is the LCA
        return node;
    }

    void displayLCA(int p, int q) {
        TreeNode* lca = findLCA(root, p, q);
        if (lca) {
            cout << "Lowest Common Ancestor of " << p << " and " << q << " is: " << lca->value << endl;
        }
        else {
            cout << "Lowest Common Ancestor not found for " << p << " and " << q << endl;
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
    int n, value, p, q;

    cout << "Enter the number of values to insert: ";
    cin >> n;

    cout << "Enter the values to insert into the BST: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        bst.insert(value);
    }

    bst.displayInorder();

    cout << "Enter two nodes to find their Lowest Common Ancestor: ";
    cin >> p >> q;

    bst.displayLCA(p, q);

    return 0;
}
