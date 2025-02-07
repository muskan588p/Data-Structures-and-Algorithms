class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n=arr.size();
        int l=1;
        int h=n-2;
        if(n==1){
            return 0;
        }
        else if(arr[0] > arr[1]){
            return 0;
        }
        else if(arr[n-1] > arr[n-2]){
            return n-1;
        }
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){
                return mid;
            }
            else if(arr[mid] < arr[mid-1] && arr[mid] > arr[mid+1]){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }  
        return -1;        
    }
};