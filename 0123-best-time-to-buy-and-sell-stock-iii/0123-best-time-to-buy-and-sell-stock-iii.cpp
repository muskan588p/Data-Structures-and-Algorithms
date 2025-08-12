class Solution {
public:
    int solve(vector<int>& prices, int idx, int buy, vector<vector<vector<int>>> &dp, int limit){
        if(idx==prices.size()){
            return 0;
        }
        if(limit==0){
            return 0;
        }
        if(dp[idx][buy][limit] != -1){
            return dp[idx][buy][limit];
        }
        int profit=0;
        if(buy){
            int take= -prices[idx] + solve(prices, idx+1, 0, dp, limit);
            int skip= 0 + solve(prices, idx+1, 1, dp, limit);
            profit=max(take, skip);
        }
        else{
            int take= prices[idx] + solve(prices, idx+1, 1, dp, limit-1); //trans is complete only when sell
            int skip= 0 + solve(prices, idx+1, 0, dp, limit);
            profit=max(take, skip);
        }
        dp[idx][buy][limit]=profit;
        return dp[idx][buy][limit];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int limit=2;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return solve(prices, 0, 1, dp, limit);  //first one will take buy
    }
};