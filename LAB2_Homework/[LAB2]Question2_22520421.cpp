//MSSV: 22520421
//Full Name: Nguyen Thuy Hien
//Question 1
//Notes or Remarks: ......

#include <iostream>
using namespace std;

class BrowserHistory {
private:
    string backStack[100]; 
    string forwardStack[100]; 
    int backTop = -1;  
    int forwardTop = -1;  
    string currentURL;

public:
    // Visit a new URL and clear the forward stack
    void visit(const string& url) {
        if (!currentURL.empty()) {
            backStack[++backTop] = currentURL;  // Push currentURL to the back stack
        }
        currentURL = url;
        forwardTop = -1;  // Clear forward stack
        cout << "Visited: " << currentURL << endl;
    }

    // Go back to the previous URL
    void back() {
        if (backTop == -1) {
            cout << "No more back history!" << endl;
            return;
        }
        forwardStack[++forwardTop] = currentURL;  // Push currentURL to the forward stack
        currentURL = backStack[backTop--];  // Pop from the back stack
        cout << "Back to: " << currentURL << endl;
    }

    // Go forward to the next URL
    void forward() {
        if (forwardTop == -1) {
            cout << "No more forward history!" << endl;
            return;
        }
        backStack[++backTop] = currentURL;  // Push currentURL to the back stack
        currentURL = forwardStack[forwardTop--];  // Pop from the forward stack
        cout << "Forward to: " << currentURL << endl;
    }
};

int main() {
    BrowserHistory browser;
    int choice;
    string url;

    do {
        cout << "\nMenu:\n";
        cout << "1. Visit a new URL\n";
        cout << "2. Go back\n";
        cout << "3. Go forward\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter URL: ";
            cin >> url;
            browser.visit(url);
            break;
        case 2:
            browser.back();
            break;
        case 3:
            browser.forward();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
