class Solution {
public:
    int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp){
        //base case
        if(i==a.length()){
            return b.length()-j;
        }
        if(j==b.length()){
            return a.length()-i;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans=0;
        if(a[i]==b[j]){
            dp[i][j]=solve(a, b, i+1, j+1, dp);
        }
        else{
            int insertans= 1+solve(a, b, i, j+1, dp);
            int deleteans= 1+solve(a, b, i+1, j, dp);
            int replaceans= 1+solve(a, b, i+1, j+1, dp);

            dp[i][j]=min(insertans, min(deleteans, replaceans));
        }
        // dp[i][j]=ans;
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int ans=solve(word1, word2, 0, 0, dp);
        return ans;
    }
};