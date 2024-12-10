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

    int findIndex(int inorder[], int start, int end, int value) {
        for (int i = start; i <= end; ++i) {
            if (inorder[i] == value) {
                return i;
            }
        }
        return -1; // Should never happen if inputs are correct
    }

    TreeNode* buildTreeHelper(int inorder[], int postorder[], int inStart, int inEnd, int& postIndex) {
        if (inStart > inEnd) return nullptr;

        // The current root is the last element in the current postorder segment
        int rootValue = postorder[postIndex];
        TreeNode* node = new TreeNode(rootValue);
        postIndex--;

        // Find the index of the root value in the inorder array manually
        int inIndex = findIndex(inorder, inStart, inEnd, rootValue);

        // Build the right and left subtrees
        node->right = buildTreeHelper(inorder, postorder, inIndex + 1, inEnd, postIndex);
        node->left = buildTreeHelper(inorder, postorder, inStart, inIndex - 1, postIndex);

        return node;
    }

    TreeNode* buildTree(int inorder[], int postorder[], int n) {
        int postIndex = n - 1; // Start from the last element of postorder
        return buildTreeHelper(inorder, postorder, 0, n - 1, postIndex);
    }

    void inorderTraversal(TreeNode* node) {
        if (node) {
            inorderTraversal(node->left);
            cout << node->value << " ";
            inorderTraversal(node->right);
        }
    }

    void postorderTraversal(TreeNode* node) {
        if (node) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->value << " ";
        }
    }

    void displayInorder() {
        cout << "In-order Traversal: ";
        inorderTraversal(root);
        cout << endl;
    }

    void displayPostorder() {
        cout << "Post-order Traversal: ";
        postorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;

    int n;
    cout << "Enter the number of nodes in the tree: ";
    cin >> n;

    int* inorder = new int[n];
    int* postorder = new int[n];
    cout << "Enter the inorder traversal: ";
    for (int i = 0; i < n; ++i) {
        cin >> inorder[i];
    }

    cout << "Enter the postorder traversal: ";
    for (int i = 0; i < n; ++i) {
        cin >> postorder[i];
    }

    tree.root = tree.buildTree(inorder, postorder, n);

    cout << "Reconstructed Tree Traversals:" << endl;
    tree.displayInorder();
    tree.displayPostorder();

    return 0;
}
