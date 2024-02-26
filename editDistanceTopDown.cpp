#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function for calculating minimum edit distance with memoization
int minDistanceHelper(string& word1, string& word2, int i, int j, vector<vector<int>>& memo) {
    // Base cases
    if (i == 0) {
        return j; // Insert j characters
    }
    if (j == 0) {
        return i; // Delete i characters
    }

    // Check if the result is already memoized
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    // Recursive cases
    if (word1[i - 1] == word2[j - 1]) {
        // No operation needed
        memo[i][j] = minDistanceHelper(word1, word2, i - 1, j - 1, memo);
    } else {
        // Minimum of delete, insert, or replace
        memo[i][j] = 1 + min({
            minDistanceHelper(word1, word2, i - 1, j, memo),   // Delete
            minDistanceHelper(word1, word2, i, j - 1, memo),   // Insert
            minDistanceHelper(word1, word2, i - 1, j - 1, memo) // Replace
        });
    }

    return memo[i][j];
}

// Main function to calculate minimum edit distance

int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    
    // Initialize memoization table with -1
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));

    return minDistanceHelper(word1, word2, m, n, memo);
}

int main() {
    string word1 = "horse";
    string word2 = "ros";

    cout << "Minimum edit distance: " << minDistance(word1, word2) << endl;

    return 0;
}


// Time Complexity: O(m * n), where m and n are the lengths of word1 and word2 respectively
// Space Complexity: O(m * n)