#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

// Naive approach for finding the Longest Common Subsequence (LCS)
int LCS(char X[], int n, char Y[], int m) {
    if (m == 0 || n == 0) {
        return 0;
    }

    if (X[m - 1] == Y[n - 1]) {
        return 1 + LCS(X, m - 1, Y, n - 1);
    } else {
        return max(LCS(X, m - 1, Y, n), LCS(X, m, Y, n - 1));
    }
}
// Time complexity: O(2^(m+n)) - Exponential
// Space complexity: O(Length of Longest String) or O(max(m,n))

// Bottom-up dynamic programming approach for LCS
int LCS2(char X[], int m, char Y[], int n) {
    int dp[m + 1][n + 1];

    // Initialize the first row and column of the dp array
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }

    // Build the dp array in a bottom-up manner
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    return dp[m][n];
}
// Time complexity: O(m * n) - Quadratic
// Space complexity: O(m * n)

// Top-down dynamic programming approach for LCS with memoization
int LCS3(char X[], int m, char Y[], int n, int dp[][6]) {
    if (m == 0 || n == 0)
        return 0;

    if (dp[m][n] != -1) { // If it exists
        return dp[m][n];
    }

    if (X[m] == Y[n]) {
        dp[m][n] = 1 + LCS3(X, m - 1, Y, n - 1, dp);
    } else {
        dp[m][n] = max(LCS3(X, m, Y, n - 1, dp), LCS3(X, m - 1, Y, n, dp));
    }

    return dp[m][n];
}
// Time complexity: O(m * n) - Quadratic
// Space complexity: O(m * n)

int main() {
    char a[] = "HELLOK";
    char b[] = "ABOK";
    int dp[6 + 1][4 + 1];
    memset(dp, -1, sizeof(dp));

    // Finding the length of LCS using the bottom-up approach
    cout << "Length of LCS is " << LCS2(a, 6, b, 4);

    return 0;
}
/**
 *  We maintain a table for finding out LCS2
 *   ~ H E L L O (String 1 n)
 * ~ 0 0 0 0 0 0
 * W 0
 * O 0
 * R 0     *
 * L 0
 * L 0       A B
 * D 0       C D
 * (String 2 m)
 * ~ represents an empty string.
 * We have to start filling this table.
 * The last cell [n][m] = D will give the answer.
 * D = 1 + A (if chars are same)
 * D = max(B, C) (if chars are not identical)
 * O(m*n) quadratic.
 * in naive approach we were getting exponential time complexity.
 * space complexity (n+1)*(m+1).
*/