class Solution {
public:
    void getperms(vector<int>& nums, vector<vector<int>> &ans, int idx){
        //base case
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx], nums[i]);
            getperms(nums, ans, idx+1);

            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getperms(nums, ans, 0);

        return ans;
    }
};