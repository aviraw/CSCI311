#include <iostream>
#include <algorithm>

using namespace std;

// T(n,W) = T(n−1,W) + T(n−1,W−weight[n])
int knapsack(int values[], int weights[], int n, int W) {
    // Base condition
    if (n == 0 || W == 0)
        return 0;

    // If the weight of the nth item is more than the capacity W,
    // then this item cannot be included in the optimal solution.
    if (weights[n - 1] > W)
        return knapsack(values, weights, n - 1, W);

    // Return the maximum of two cases:
    // 1. nth item included
    // 2. not included
    else
        return max(values[n - 1] + knapsack(values, weights, n - 1, W - weights[n - 1]),
                   knapsack(values, weights, n - 1, W));
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(values) / sizeof(values[0]);

    cout << "Maximum value in knapsack = " << knapsack(values, weights, n, W) << endl;

    return 0;
}

// T -> O(2^n)
// S -> O(n)