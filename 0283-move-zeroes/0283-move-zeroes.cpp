class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        while(i<j){
            if(nums[i]==0 && nums[j]!=0){
                swap(nums[i], nums[j]);
            }
            i++;
            j--;
        }
    }
};