class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        while(s<=e){
            int m=s + (e-s)/2;
            if(target==nums[m]){
                return m;
            }
            if(nums[s] <= nums[m]){    //left sorted
                if(nums[s] <= target && target <= nums[m]){
                    e=m-1;
                }
                else{
                    s=m+1;
                }
            }
            else{  //right sorted
                if(nums[m] <= target && target <= nums[e]){
                    s=m+1;
                }
                else{
                    e=m-1;
                }
            }
        }
        return -1;
    }
};