class Solution {
public:
    bool solve(vector<int>& nums, int n, int sum, vector<vector<int>> &dp){
        if (sum == 0) {
            return true;
        }
        if (n == 0) {
            return false;
        }
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }

        if(nums[n-1] <= sum){
            dp[n][sum]=solve(nums, n-1, sum-nums[n-1], dp) || solve(nums, n-1, sum, dp);
        }
        else{
            dp[n][sum]=solve(nums, n-1, sum, dp);
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2 != 0){
            return false;
        }
        sum=sum/2;
        //after making sum half then make 2d vector with sum as half sum
        vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
        int ans=solve(nums, n, sum, dp);
        return ans;
    }
};