#include <iostream>
#include <string>
using namespace std;

class FileNode {
public:
    string name;
    FileNode* children[10];
    int childCount;

    FileNode(string name) : name(name), childCount(0) {}

    void addChild(string childName) {
        if (childCount < 10) {
            children[childCount++] = new FileNode(childName);
        }
        else {
            cout << "Maximum child limit reached!" << endl;
        }
    }

    void removeChild(string childName) {
        for (int i = 0; i < childCount; ++i) {
            if (children[i]->name == childName) {
                delete children[i];
                for (int j = i; j < childCount - 1; ++j) {
                    children[j] = children[j + 1];
                }
                childCount--;
                return;
            }
        }
        cout << "Child not found!" << endl;
    }

    void listChildren() {
        for (int i = 0; i < childCount; ++i) {
            cout << children[i]->name << endl;
        }
    }
};

int main() {
    FileNode* root = new FileNode("root");
    root->addChild("Folder1");
    root->addChild("Folder2");
    root->listChildren();
    root->removeChild("Folder1");
    root->listChildren();
    return 0;
}
