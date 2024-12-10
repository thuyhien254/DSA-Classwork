#include <iostream>
#include <string>
using namespace std;

class MerkleNode {
public:
    string hash;
    MerkleNode* left;
    MerkleNode* right;

    MerkleNode(string data) : hash(data), left(nullptr), right(nullptr) {}
};

class MerkleTree {
public:
    MerkleNode* buildTree(MerkleNode* nodes[], int size) {
        while (size > 1) {
            int newSize = 0;
            for (int i = 0; i < size; i += 2) {
                if (i + 1 < size) {
                    string combinedHash = nodes[i]->hash + nodes[i + 1]->hash;
                    nodes[newSize++] = new MerkleNode(combinedHash);
                }
                else {
                    nodes[newSize++] = nodes[i];
                }
            }
            size = newSize;
        }
        return nodes[0];
    }
};

int main() {
    string data[] = { "block1", "block2", "block3", "block4" };
    MerkleNode* nodes[4];

    for (int i = 0; i < 4; i++) {
        nodes[i] = new MerkleNode(data[i]);
    }

    MerkleTree mt;
    MerkleNode* root = mt.buildTree(nodes, 4);
    cout << "Merkle Root: " << root->hash << endl;
    return 0;
}
