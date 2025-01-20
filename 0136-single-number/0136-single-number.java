class Solution {
    int ans=0;
    public int singleNumber(int[] nums) {
        for(int i=0;i<nums.length;i++){
            ans=ans^nums[i];
        }
        return ans;
    }
}