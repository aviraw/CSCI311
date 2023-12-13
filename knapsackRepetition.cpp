#include <iostream>
#include <algorithm>
using namespace std;

int unboundedKnapsack(int values[], int weights[], int n, int W) {
    int dp[W + 1];
    
    // Initialize the dp array
    for (int w = 0; w <= W; ++w) {
        dp[w] = 0;
    }
    
    // Build the dp array in a bottom-up manner
    for (int w = 1; w <= W; ++w) {
        for (int i = 0; i < n; ++i) {
            if (weights[i] <= w) {
                dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
            }
        }
    }
    
    return dp[W];
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(values) / sizeof(values[0]);

    cout << "Maximum value in repetition knapsack = " << unboundedKnapsack(values, weights, n, W) << endl;

    return 0;
}
// Time Complexity: O(n * W)
// Space Complexity: O(W)