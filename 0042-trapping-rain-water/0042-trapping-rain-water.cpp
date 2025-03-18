class Solution {
public:
    int trap(vector<int>& arr) {   //height=arr
        int n=arr.size();
        vector<int> lmax(n,0);
        vector<int> rmax(n,0);

        //initialize
        lmax[0]=arr[0];
        rmax[n-1]=arr[n-1];

        for(int i=1;i<n;i++){
            lmax[i]=max(lmax[i-1], arr[i]);
        }

        for(int i=n-2;i>=0;i--){
            rmax[i]=max(rmax[i+1] , arr[i]);
        }

        int total=0;
        for(int i=0;i<n;i++){
            total+= (min(lmax[i], rmax[i])) - arr[i];
        }
        return total;
    }
};