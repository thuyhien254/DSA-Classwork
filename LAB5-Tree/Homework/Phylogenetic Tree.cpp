#include <iostream>
#include <string>
using namespace std;

class PhyloNode {
public:
    string species;
    PhyloNode* left;
    PhyloNode* right;

    PhyloNode(string name) : species(name), left(nullptr), right(nullptr) {}
};

void displayTree(PhyloNode* node, int level = 0) {
    if (!node) return;

    for (int i = 0; i < level; ++i) cout << "  ";
    cout << node->species << endl;

    displayTree(node->left, level + 1);
    displayTree(node->right, level + 1);
}

int main() {
    PhyloNode* root = new PhyloNode("CommonAncestor");
    root->left = new PhyloNode("SpeciesA");
    root->right = new PhyloNode("SpeciesB");

    root->left->left = new PhyloNode("SpeciesC");
    root->left->right = new PhyloNode("SpeciesD");

    displayTree(root);
    return 0;
}
