class Solution {
public:
    int binsearch(vector<int>& nums, int target, int st, int end) {
        if(st<=end){
            int mid=st + (end-st)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(target>nums[mid]){
                return binsearch(nums, target, mid+1, end);
            }
            else{
                return binsearch(nums, target, st, mid-1);
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target){
        return binsearch(nums, target, 0, nums.size()-1);
    }
};