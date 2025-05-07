class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill the table bottom-up
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];  
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);  
                }
            }
        }
        return dp[0][0];  // answer is at the top-left corner
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        int lenoflcs= longestCommonSubsequence(word1, word2);   //formula
        return n + m -2*lenoflcs;
    }
};