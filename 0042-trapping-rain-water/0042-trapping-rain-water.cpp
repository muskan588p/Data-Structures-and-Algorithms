class Solution {
public:
    int trap(vector<int>& arr) {  //height=arr
        int n=arr.size();
        int l=0; int r=n-1;    //indices
        int lmax=0; int rmax=0;
        int ans=0;

        while(l<r){
            lmax=max(lmax, arr[l]);
            rmax=max(rmax, arr[r]);

            if(lmax<rmax){
                ans+=lmax-arr[l];    //jis index pr hai ussi ko add krenge
                l++;
            }
            else{
                ans+=rmax-arr[r];
                r--;
            }
        }
        return ans;
    }
};