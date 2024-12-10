#include <iostream>
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
        if (!node) return new TreeNode(value);
        if (value < node->value) node->left = insert(node->left, value);
        else node->right = insert(node->right, value);
        return node;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    TreeNode* findLCA(TreeNode* node, int p, int q) {
        if (!node) return nullptr;

        // If the current node matches either p or q, return it
        if (node->value == p || node->value == q) return node;

        // Recur for left and right subtrees
        TreeNode* leftLCA = findLCA(node->left, p, q);
        TreeNode* rightLCA = findLCA(node->right, p, q);

        // If both left and right are non-null, this is the LCA
        if (leftLCA && rightLCA) return node;

        // Otherwise, return the non-null node
        return leftLCA ? leftLCA : rightLCA;
    }

    void displayLCA(int p, int q) {
        TreeNode* lca = findLCA(root, p, q);
        if (lca) {
            cout << "Lowest Common Ancestor of " << p << " and " << q << ": " << lca->value << endl;
        }
        else {
            cout << "Lowest Common Ancestor not found.\n";
        }
    }
};

int main() {
    BinaryTree tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(15);
    tree.insert(25);
    tree.insert(35);

    tree.displayLCA(5, 15);
    tree.displayLCA(5, 30);
    tree.displayLCA(15, 35);

    return 0;
}
