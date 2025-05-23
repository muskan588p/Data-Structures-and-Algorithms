class Solution {
public:
    int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp){
        //base case
        if(i==a.length() || j==b.length()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans=0;
        if(a[i]==b[j]){
            dp[i][j]= 1 + solve(a, b, i+1, j+1, dp);
        }
        else{
            dp[i][j]= max(solve(a, b, i+1, j, dp), solve(a, b, i, j+1, dp));
        }
        // dp[i][j]=ans;
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(text1, text2, 0, 0, dp);
    }
};