//MSSV: 22520421
//Full Name: Nguyen Thuy Hien
//Question 2
//Notes or Remarks: ......
#include <iostream>

using namespace std;

const int MAX_DISKS = 3; // Number of disks

// Function to display the current state of the towers
void displayTowers(int A[], int B[], int C[]) {
    cout << "=========================" << endl;
    cout << "A Tower" << endl;
    cout << "STACK = < ";
    for (int i = 0; i < MAX_DISKS; ++i) {
        if (A[i] != 0) cout << A[i] << " ";
    }
    cout << ">" << endl;

    cout << "=========================" << endl;
    cout << "B Tower" << endl;
    cout << "STACK = < ";
    for (int i = 0; i < MAX_DISKS; ++i) {
        if (B[i] != 0) cout << B[i] << " ";
    }
    cout << ">" << endl;

    cout << "=========================" << endl;
    cout << "C Tower" << endl;
    cout << "STACK = < ";
    for (int i = 0; i < MAX_DISKS; ++i) {
        if (C[i] != 0) cout << C[i] << " ";
    }
    cout << ">" << endl;
    cout << "=========================" << endl;
}

// Function to move a disk from one tower to another
bool moveDisk(int from[], int to[]) {
    int fromIndex = -1, toIndex = -1;
    // Find the top disk in 'from' tower
    for (int i = MAX_DISKS - 1; i >= 0; --i) {
        if (from[i] != 0) {
            fromIndex = i;
            break;
        }
    }
    // Find the top empty position in 'to' tower
    for (int i = 0; i < MAX_DISKS; ++i) {
        if (to[i] == 0) {
            toIndex = i;
            break;
        }
    }
    if (fromIndex == -1 || (toIndex > 0 && to[toIndex - 1] < from[fromIndex])) {
        return false; // Invalid move
    }

    // Move the disk
    to[toIndex] = from[fromIndex];
    from[fromIndex] = 0;
    return true;
}

int main() {
    // Towers initialized as arrays
    int A[MAX_DISKS] = { 3, 2, 1 }; // Tower A with all disks
    int B[MAX_DISKS] = { 0 };       // Tower B (empty)
    int C[MAX_DISKS] = { 0 };       // Tower C (empty)

    int choice;
    cout << "========= Demo Stack ==========" << endl;
    cout << "0. Creating Tower." << endl;
    cout << "1. A -> B" << endl;
    cout << "2. B -> A" << endl;
    cout << "3. B -> C" << endl;
    cout << "4. C -> B" << endl;
    cout << "5. C -> A" << endl;
    cout << "6. A -> C" << endl;

    while (true) {
        displayTowers(A, B, C); // Display current tower status
        cout << "Please input: ";
        cin >> choice;

        // Perform the move based on user's choice
        switch (choice) {
        case 1: // A -> B
            if (!moveDisk(A, B)) {
                cout << "Invalid move!" << endl;
            }
            break;
        case 2: // B -> A
            if (!moveDisk(B, A)) {
                cout << "Invalid move!" << endl;
            }
            break;
        case 3: // B -> C
            if (!moveDisk(B, C)) {
                cout << "Invalid move!" << endl;
            }
            break;
        case 4: // C -> B
            if (!moveDisk(C, B)) {
                cout << "Invalid move!" << endl;
            }
            break;
        case 5: // C -> A
            if (!moveDisk(C, A)) {
                cout << "Invalid move!" << endl;
            }
            break;
        case 6: // A -> C
            if (!moveDisk(A, C)) {
                cout << "Invalid move!" << endl;
            }
            break;
        default:
            cout << "Invalid input! Try again." << endl;
            break;
        }

        // Check completed 
        if (C[0] == 3 && C[1] == 2 && C[2] == 1) {
            cout << "You solved the puzzle!" << endl;
            displayTowers(A, B, C);
            break;
        }
    }

    return 0;
}
