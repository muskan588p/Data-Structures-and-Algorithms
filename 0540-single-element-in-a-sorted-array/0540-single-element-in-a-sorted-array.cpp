class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n=a.size();
        if(n==1){
            return a[0];
        }
        if(a[0] != a[1]){
            return a[0];
        }
        if(a[n-1] != a[n-2]){
            return a[n-1];
        }
        int l=0;
        int h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(a[mid-1] != a[mid] && a[mid] != a[mid+1]){
                return a[mid];
            }
            if(mid % 2==1 && a[mid] == a[mid-1] ||
               mid % 2==0 && a[mid] == a[mid+1]){   //eliminate left half, ele is in right
                l=mid+1;
            }
            else{                                  //eliminate right half, ele is in left
                h=mid-1;
            }
        }
        return -1;
    }
};