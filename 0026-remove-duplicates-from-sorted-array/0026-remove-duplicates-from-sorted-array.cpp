class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        int idx=0;
        for(auto it : s){      //Iterate over the elements in the set
            nums[idx] = it;    //copy them back to the nums array
            idx++;
        }
        return idx;
    }
};