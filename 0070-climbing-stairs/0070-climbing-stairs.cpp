class Solution {
public:
    int climbStairs(int n) {
        //tabulation
        vector<int> dp(n+1, -1);
        dp[0]=1;  // 1 way to stay at step 0
        dp[1] = 1; // 1 way to reach step 1

        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};