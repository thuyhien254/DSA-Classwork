//MSSV:22520421
//Full Name: Nguyen Thuy Hien
//Question 4
//Notes or Remarks: ......

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        deque<int> q;

        // Traverse prices in reverse order
        for (int i = n; i > 0; --i) {
            // Remove elements from the front that cannot be used
            while (!q.empty() && q.front() > i * 2 + 1) {
                q.pop_front();
            }
            // If we're in the left half of the prices, we can add the value
            if (i <= (n - 1) / 2) {
                prices[i - 1] += prices[q.front() - 1];
            }
            // Remove elements from the back if they are greater than or equal to the current price
            while (!q.empty() && prices[q.back() - 1] >= prices[i - 1]) {
                q.pop_back();
            }
            // Add the current index to the deque
            q.push_back(i);
        }
        // The result will be the first element in the modified prices array
        return prices[0];
    }
};

int main() {
    Solution solution;

    int n; // Number of fruits
    cout << "Enter the number of fruits: ";
    cin >> n;

    vector<int> prices(n); // Vector to store prices of fruits
    cout << "Enter the prices of the fruits: ";
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    // Call the method and output the result
    int result = solution.minimumCoins(prices);
    cout << "Minimum number of coins necessary: " << result << endl;

    return 0;
}
