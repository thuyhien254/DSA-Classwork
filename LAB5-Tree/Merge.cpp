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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return nullptr;
        if (!t1) return t2;
        if (!t2) return t1;

        // Create a new node with the sum of t1 and t2's values
        TreeNode* merged = new TreeNode(t1->value + t2->value);

        // Recursively merge left and right subtrees
        merged->left = mergeTrees(t1->left, t2->left);
        merged->right = mergeTrees(t1->right, t2->right);

        return merged;
    }

    void inorderTraversal(TreeNode* node) {
        if (node) {
            inorderTraversal(node->left);
            cout << node->value << " ";
            inorderTraversal(node->right);
        }
    }

    void displayInorder(TreeNode* root) {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree1, tree2;

    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(3);
    t1->right = new TreeNode(2);
    t1->left->left = new TreeNode(5);

    TreeNode* t2 = new TreeNode(2);
    t2->left = new TreeNode(1);
    t2->right = new TreeNode(3);
    t2->left->right = new TreeNode(4);
    t2->right->right = new TreeNode(7);

    BinaryTree mergedTree;
    TreeNode* mergedRoot = mergedTree.mergeTrees(t1, t2);

    cout << "In-order Traversal of Merged Tree: ";
    mergedTree.displayInorder(mergedRoot);

    return 0;
}
