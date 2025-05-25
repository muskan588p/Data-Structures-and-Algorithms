class Solution {
public:
    int solve(vector<int>& nums, int n, int curr, int prev, vector<vector<int>> &dp){
        //base case
        if(curr==n){
            return 0;
        }
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }

        int take=0;                             //include
        if(prev==-1 || nums[curr] > nums[prev]){
            take= 1 + solve(nums, n, curr+1, curr, dp);
        }
        int notake=0 + solve(nums, n, curr+1, prev, dp);   // exclude
        dp[curr][prev+1]=max(take, notake);

        return dp[curr][prev+1];

    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(nums, n, 0, -1, dp);
    }
};