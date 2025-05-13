class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        // Calculate the total sum of the array
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        // If the sum is odd, we cannot split the array into two equal subsets
        if (sum % 2 != 0) {
            return false;
        }

        // Target sum for each subset is half of the total sum
        sum /= 2;

        // DP table, where dp[i][j] means whether we can form sum 'j' using first 'i' elements
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        // Base case: we can always form a sum of 0 (by not picking any elements)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];  // Include or exclude the current element
                } else {
                    dp[i][j] = dp[i - 1][j];  // Exclude the current element
                }
            }
        }

        // The answer is whether we can form the target sum using all elements
        return dp[n][sum];
    }
};
