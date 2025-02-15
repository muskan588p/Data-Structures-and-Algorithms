class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,1);    
        vector<int> pre(n,1);
        vector<int> suf(n,1);

        //prefix
        pre[0]=1;
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1] * nums[i-1];
        }

        //suffix
        suf[n-1]=1;
        for(int i=n-2;i>=0;i--){
            suf[i]= suf[i+1] * nums[i+1];
        }

        //ans
        for(int i=0;i<n;i++){
            ans[i]=pre[i] * suf[i];
        }
        return ans;
    }
};