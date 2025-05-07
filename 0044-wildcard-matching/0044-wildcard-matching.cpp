class Solution {
public:
    bool solve(string &s, string &p, int i, int j, vector<vector<int>> &dp){
        //base case
        if(i<0 && j<0){   //string traversal is over(-ve)
            return true;
        }
        if(i>=0 && j<0){
            return false;
        }
        if(i<0 && j>=0){
            for(int k=0;k<=j;k++){
                if(p[k] != '*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        //macth
        if(s[i]==p[j] || p[j]=='?'){
            dp[i][j]=solve(s, p, i-1, j-1, dp);
        }
        else if(p[j]=='*'){
            dp[i][j]=solve(s, p, i-1, j, dp) || solve(s, p, i, j-1, dp);
        }
        else{
            return false;
        }
        return dp[i][j];
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(s, p, n-1, m-1, dp);
    }
};