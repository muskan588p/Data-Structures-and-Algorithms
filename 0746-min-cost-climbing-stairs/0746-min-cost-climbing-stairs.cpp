// class Solution {
// public:
// int solve(vector<int>& cost, int n, vector<int>& dp){
//         if(n==0){
//             return cost[0];
//         }
//         if(n==1){
//             return cost[1];
//         }
//         //step 3
//         if(dp[n] != -1){
//             return dp[n];
//         }
//         //step 2
//         dp[n] = cost[n] + min(solve(cost, n-1, dp), solve(cost, n-2, dp));
//         return dp[n];
        
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n=cost.size();

//         //step 1
//         vector<int> dp(n+1, -1);
//         int ans = min( solve(cost, n-1, dp), solve(cost, n-2, dp));
//         return ans;
//     }
// };

class Solution {
public:
int solve(vector<int>& cost, int n){
    //step 1
    vector<int> dp(n+1);

    //step 2
    dp[0]= cost[0];
    dp[1]= cost[1];
        
    //step 3
    for(int i=2;i<=n-1; i++){
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }
    return min(dp[n-1], dp[n-2]);
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();

        int ans= solve(cost, n);
        return ans;
    }
};