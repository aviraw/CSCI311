#include <iostream>
#include <vector>
using namespace std;

// Function to calculate minimum edit distance using dynamic programming
// Time Complexity: O(m * n), where m and n are the lengths of word1 and word2 respectively
// Space Complexity: O(m * n), the size of the DP array
int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();

    // Create a 2D DP array to store the minimum operations required
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP array based on the minimum edit distance algorithm
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0)
                dp[i][j] = j; // Insert j characters
            else if (j == 0)
                dp[i][j] = i; // Delete i characters
            else if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1]; // No operation needed
            else
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                // Minimum of delete, insert, or replace
        }
    }

    return dp[m][n]; // Minimum operations required to transform word1 to word2
}

int main() {
    string word1 = "horse";
    string word2 = "ros";

    cout << "Minimum edit distance: " << minDistance(word1, word2) << endl;

    return 0;
}
