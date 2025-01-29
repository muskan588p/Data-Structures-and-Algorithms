class Solution {
public:
    void getallsubsets(vector<int>& arr, vector<int>& ans, int i, vector<vector<int>> &allsubsets){
        //base case
        if(i==arr.size()){
            allsubsets.push_back(ans);
            return;
        }
        ans.push_back(arr[i]);
        getallsubsets(arr,ans,i+1,allsubsets);

        ans.pop_back();

        getallsubsets(arr,ans,i+1,allsubsets);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allsubsets;
        vector<int> ans;

        getallsubsets(nums,ans,0, allsubsets);

        return allsubsets;
    }
};