class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int> &dp){
        int n=coins.size();
        //base case
        if(amount==0){
            return 0;   //0 coins required
        }
        if(amount<0){
            return INT_MAX;
        }
        if(dp[amount] != -1){
            return dp[amount];
        }

        int mincoins=INT_MAX;
        for(int i=0;i<n;i++){
            int ans=solve(coins, amount-coins[i], dp);
            if(ans != INT_MAX){
                mincoins= min(mincoins, 1+ans);
            }
        }
        dp[amount]=mincoins;
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int ans=solve(coins, amount, dp);

        if(ans==INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
    }
};