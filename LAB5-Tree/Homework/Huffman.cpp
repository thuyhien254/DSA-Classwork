#include <iostream>
#include <string>
using namespace std;

class HuffmanNode {
public:
    char ch;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

class HuffmanTree {
public:
    HuffmanNode* root;

    HuffmanTree(char c, int freq) {
        root = new HuffmanNode(c, freq);
    }

    void display(HuffmanNode* node, string code) {
        if (!node) return;
        if (node->ch != '\0') {
            cout << node->ch << ": " << code << endl;
        }
        display(node->left, code + "0");
        display(node->right, code + "1");
    }
};

int main() {
    HuffmanTree tree('a', 10);
    tree.root->left = new HuffmanNode('b', 5);
    tree.root->right = new HuffmanNode('c', 5);

    tree.display(tree.root, "");
    return 0;
}
