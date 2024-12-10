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

    TreeNode* search(TreeNode* node, int value) {
        if (!node || node->value == value) {
            return node;
        }
        if (value < node->value) {
            return search(node->left, value);
        }
        else {
            return search(node->right, value);
        }
    }

    bool search(int value) {
        return search(root, value) != nullptr;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    TreeNode* remove(TreeNode* node, int value) {
        if (!node) return node;

        if (value < node->value) {
            node->left = remove(node->left, value);
        }
        else if (value > node->value) {
            node->right = remove(node->right, value);
        }
        else {
            // Node with one child or no child
            if (!node->left) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children
            TreeNode* temp = findMin(node->right);
            node->value = temp->value;
            node->right = remove(node->right, temp->value);
        }
        return node;
    }

    void remove(int value) {
        root = remove(root, value);
    }

    void inorderTraversal(TreeNode* node) {
        if (node) {
            inorderTraversal(node->left);
            cout << node->value << " ";
            inorderTraversal(node->right);
        }
    }

    void display() {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    int choice, value;

    while (true) {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert a value into the tree\n";
        cout << "2. Search for a value in the tree\n";
        cout << "3. Remove a value from the tree\n";
        cout << "4. Display the tree (Inorder Traversal)\n";
        cout << "5. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> value;
            tree.insert(value);
            cout << "Inserted value " << value << " into the tree.\n";
            break;
        case 2:
            cout << "Enter the value to search: ";
            cin >> value;
            if (tree.search(value)) {
                cout << "Value " << value << " exists in the tree.\n";
            }
            else {
                cout << "Value " << value << " does not exist in the tree.\n";
            }
            break;
        case 3:
            cout << "Enter the value to remove: ";
            cin >> value;
            tree.remove(value);
            cout << "Removed value " << value << " from the tree.\n";
            break;
        case 4:
            cout << "Current tree (Inorder Traversal): ";
            tree.display();
            break;
        case 5:
            cout << "Exiting the program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
