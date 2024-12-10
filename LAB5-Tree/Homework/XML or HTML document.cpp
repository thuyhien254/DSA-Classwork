#include <iostream>
#include <string>
using namespace std;

class XmlNode {
public:
    string tagName;
    XmlNode* children[10];
    int childCount;

    XmlNode(string tag) : tagName(tag), childCount(0) {}

    void addChild(XmlNode* child) {
        if (childCount < 10) {
            children[childCount++] = child;
        }
    }

    void display(int depth = 0) {
        for (int i = 0; i < depth; i++) cout << "  ";
        cout << "<" << tagName << ">" << endl;

        for (int i = 0; i < childCount; ++i) {
            children[i]->display(depth + 1);
        }

        for (int i = 0; i < depth; i++) cout << "  ";
        cout << "</" << tagName << ">" << endl;
    }
};

int main() {
    XmlNode* root = new XmlNode("html");
    XmlNode* body = new XmlNode("body");
    XmlNode* div = new XmlNode("div");

    root->addChild(body);
    body->addChild(div);

    root->display();
    return 0;
}
