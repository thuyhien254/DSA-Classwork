#include <iostream>
#include <climits> // For INT_MIN
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

    int maxPathSumHelper(TreeNode* node, int& maxSum) {
        if (!node) return 0;

        // Recursively calculate the maximum path sum for left and right subtrees
        int leftSum = max(0, maxPathSumHelper(node->left, maxSum)); // Discard negative sums
        int rightSum = max(0, maxPathSumHelper(node->right, maxSum));

        // Calculate the path sum passing through the current node
        int currentSum = node->value + leftSum + rightSum;

        // Update the global maximum path sum
        maxSum = max(maxSum, currentSum);

        // Return the maximum path sum including the current node
        return node->value + max(leftSum, rightSum);
    }

    int maxPathSum() {
        int maxSum = INT_MIN;
        maxPathSumHelper(root, maxSum);
        return maxSum;
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
    cout << "Maximum Path Sum: " << tree.maxPathSum() << endl;

    return 0;
}
