#include <iostream>
#include <algorithm>
using namespace std;

int zeroOneKnapsack(int values[], int weights[], int n, int W) {
    int dp[n + 1][W + 1];
    
    // Initialize the dp array
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            dp[i][w] = 0;
        }
    }
    
    // Build the dp array in a bottom-up manner
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    return dp[n][W];
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(values) / sizeof(values[0]);

    cout << "Maximum value in 0/1 knapsack = " << zeroOneKnapsack(values, weights, n, W) << endl;

    return 0;
}
// Time Complexity: O(n * W)
// Space Complexity: O(n * W)