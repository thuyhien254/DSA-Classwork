#include <iostream>
using namespace std;

class BrowserHistory {
private:
    string history[100];  
    int currentIndex;
    int lastIndex;

public:
    BrowserHistory(string homepage) {
        history[0] = homepage;
        currentIndex = 0;
        lastIndex = 0;
    }

    void visit(string url) {
        currentIndex++;
        history[currentIndex] = url;
        lastIndex = currentIndex;  // Xóa lịch sử forward
    }

    string back(int steps) {
        currentIndex = (steps > currentIndex) ? 0 : currentIndex - steps;
        return history[currentIndex];
    }

    string forward(int steps) {
        currentIndex = (steps + currentIndex > lastIndex) ? lastIndex : currentIndex + steps;
        return history[currentIndex];
    }
};

int main() {
    int n;
    cout << "Number of operations ";
    cin >> n;
    string homepage;
    cout << "BrowserHistory"<<" ";
    cin >> homepage;

    BrowserHistory browser(homepage);

    

    for (int i = 0; i < n; ++i) {
        string operation;
        cin >> operation;

        if (operation == "visit") {
            string url;
            cin >> url;
            browser.visit(url);
        }
        else if (operation == "back") {
            int steps;
            cin >> steps;
            cout << browser.back(steps) << endl;
        }
        else if (operation == "forward") {
            int steps;
            cin >> steps;
            cout << browser.forward(steps) << endl;
        }
    }

    return 0;
}
