class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        
        int maxsum=INT_MIN;
        int currsum=0;
        for(int i=0;i<n;i++){
            currsum+=nums[i];
            maxsum= max(maxsum, currsum);

            if(currsum < 0){    //negative
                currsum=0;      //then reset to 0
            } 
            
        }
        return maxsum;
    }
};