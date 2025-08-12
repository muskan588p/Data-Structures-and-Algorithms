class Solution {
public:
    int solve(vector<int>& prices, int idx, int buy, vector<vector<int>> &dp){
        if(idx==prices.size()){
            return 0;
        }
        if(dp[idx][buy] != -1){
            return dp[idx][buy];
        }
        int profit=0;
        if(buy){
            int take= -prices[idx] + solve(prices, idx+1, 0, dp);
            int skip= 0 + solve(prices, idx+1, 1, dp);
            profit=max(take, skip);
        }
        else{
            int take= prices[idx] + solve(prices, idx+1, 1, dp);
            int skip= 0 + solve(prices, idx+1, 0, dp);
            profit=max(take, skip);
        }
        dp[idx][buy]=profit;
        return dp[idx][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, 0, 1, dp);  //first one will take buy
    }
};