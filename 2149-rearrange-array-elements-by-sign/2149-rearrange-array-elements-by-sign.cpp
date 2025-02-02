class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int posidx=0;                    //array starts from positve no.
        int negidx=1;
        for(int i=0;i<n;i++){
            if(nums[i] < 0){              //negative 
                ans[negidx]=nums[i];
                negidx+=2;
            }
            else{                         //positive
                ans[posidx]=nums[i];
                posidx+=2;
            }
        }
        return ans;
    }
};