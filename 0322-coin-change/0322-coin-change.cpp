class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX); 
        dp[0] = 0;  // Base case: 0 coins are needed to make amount 0

        // Iterate over all amounts from 1 to amount
        for (int i = 1; i <= amount; i++) {
            // Try each coin using index-based loop
            for (int j = 0; j < coins.size(); j++) {
                int coin = coins[j];
                if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        if(dp[amount] == INT_MAX){
            return -1;
        }
        return dp[amount];  
    }
};
