#include <iostream>
#include <string>
using namespace std;

class EmployeeNode {
public:
    string name;
    EmployeeNode* subordinates[10];
    int subCount;

    EmployeeNode(string name) : name(name), subCount(0) {}

    void addSubordinate(string empName) {
        if (subCount < 10) {
            subordinates[subCount++] = new EmployeeNode(empName);
        }
    }

    void displayHierarchy(int level = 0) {
        for (int i = 0; i < level; ++i) cout << "  ";
        cout << name << endl;

        for (int i = 0; i < subCount; ++i) {
            subordinates[i]->displayHierarchy(level + 1);
        }
    }
};

int main() {
    EmployeeNode* ceo = new EmployeeNode("CEO");
    ceo->addSubordinate("Manager1");
    ceo->addSubordinate("Manager2");

    ceo->subordinates[0]->addSubordinate("Employee1");
    ceo->subordinates[0]->addSubordinate("Employee2");

    ceo->subordinates[1]->addSubordinate("Employee3");

    ceo->displayHierarchy();
    return 0;
}
