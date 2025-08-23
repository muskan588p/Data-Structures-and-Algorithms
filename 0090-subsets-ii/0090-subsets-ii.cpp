class Solution {
public:
    void getallsubsets(vector<int>& arr, vector<int>& ans, int i, vector<vector<int>> &allsubsets){
        int n=arr.size();
        if(i==arr.size()){
            allsubsets.push_back(ans);
            return;                   //base case return is imporant
        }
        ans.push_back(arr[i]);
        getallsubsets(arr,ans,i+1, allsubsets);  //for include use i

        ans.pop_back();

        int idx=i+1; //--------------------------
        while(idx<n && arr[idx]==arr[idx-1]){
            idx++;
        }
        getallsubsets(arr,ans,idx, allsubsets); //for exclude use idx
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allsubsets;
        vector<int> ans;

        getallsubsets(nums,ans,0,allsubsets);
        return allsubsets;
    }
};