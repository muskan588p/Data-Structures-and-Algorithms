class Solution {
public:
    int solve(vector<int>& nums, int n, vector<int> &dp){
        if(n<0){
            return 0;
        }
        if(n==0){
            return nums[0];
        }
         if(dp[n] != -1) {
            return dp[n];
        }
        int inc=solve(nums, n-2, dp) + nums[n];
        int exc=solve(nums, n-1, dp) + 0;

        dp[n]= max(inc, exc);
        return dp[n];
        
    }
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1){
            return nums[0];
        }
        // vector<int> dp(n+1, -1);
        vector<int> first, second;
        for(int i=0;i<n;i++){
            if(i!=n-1){
                first.push_back(nums[i]);
            }
            if(i!=0){
                second.push_back(nums[i]);
            }
        }
        vector<int> dp1(first.size(), -1);
        vector<int> dp2(second.size(), -1);
        // return max(solve(first, n-1, dp), solve(second, n-1, dp));
        return max(solve(first, first.size()-1, dp1), solve(second, second.size()-1, dp2));
    }
};