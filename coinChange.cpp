#include <algorithm>
#include <iostream>
using namespace std;

// Top-Down Approach
int generateMinCoins(int amount, int numCoins, int coins[])
{
    if (amount == 0)
        return 0;

    if (amount < 0)
        return __INT32_MAX__;

    int minCoins = __INT32_MAX__;

    for (int i = 0; i < numCoins; i++)
    {
        int subSol = generateMinCoins(amount - coins[i], numCoins, coins);
        if (subSol != __INT32_MAX__)
        {
            minCoins = min(1 + subSol, minCoins);
        }
    }

    return minCoins;
}

// Bottom-Up Approach
int generateMinCoins2(int amount, int numCoins, int coins[], int dp[])
{
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        dp[i] = __INT32_MAX__;
        for (int j = 0; j < numCoins; j++)
        {

            if (i >= coins[j])
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    return dp[amount];
}

int main()
{
    int coins[] = {1, 2, 5, 10};
    int dp[14]; // Increase the size to accommodate dp[13]

    cout << "Result (Top-Down): " << generateMinCoins(13, 4, coins) << endl;

    cout << "Result (Bottom-Up): " << generateMinCoins2(13, 4, coins, dp) << endl;

    return 0;
}
// Time Complexity: O(amount * numCoins)
// Space Complexity: O(amount)