#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// Dynamic Programming approach with 1D array
int dpRodCutting1D(int price[], int n) {
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        int maxVal = INT_MIN;  // Declare maxVal and initialize it to the smallest possible integer value

        for (int j = 0; j < i; ++j) {
            maxVal = max(maxVal, price[j] + dp[i - j - 1]);
        }

        dp[i] = maxVal;  // Assign maxVal to dp[i]
    }

    return dp[n];
}

int main() {
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price) / sizeof(price[0]);

    cout << "Maximum obtainable value (DP with 1D array): " << dpRodCutting1D(price, n) << endl;

    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(n)