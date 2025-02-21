class Solution {
public:
    set<vector<int>> s;
    void combsum(vector<int>& candidates,int i,vector<vector<int>> &ans, vector<int> &comb, int target){
        int n= candidates.size();
        if(i==n){
            // ans.push_back(comb);
            return;
        }
        if(target==0){         //check if com is already added in the ans vector
            if(s.find(comb) == s.end()){
                ans.push_back(comb);
                s.insert(comb);
            }
        }
        if(target<0){
            return;
        }
        comb.push_back(candidates[i]);
        combsum(candidates, i+1, ans, comb, target-candidates[i]); //include once
        combsum(candidates, i, ans, comb, target-candidates[i]); //include multiplet imes

        comb.pop_back();      //backtrack
        combsum(candidates, i+1, ans, comb, target); //exclude
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        combsum(candidates, 0, ans, comb, target);

        return ans;
    }
};