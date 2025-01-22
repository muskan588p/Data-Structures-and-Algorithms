class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int count=0;

        for(int i=1;i<n;i++){             //start from 1 index
            if(nums[i-1] > nums[i]){
                count++;
            }
        }
        if(nums[n-1] > nums[0]){          //check for last and first ele
            count++;
        }
        if(count <= 1){
            return true;
        }
        return false;
    }
};