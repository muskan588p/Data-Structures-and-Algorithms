class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int s=1;
        int e=n-2;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){
                return mid;
            }
            else if(arr[mid-1] < arr[mid]){   //increasing slope, search in right
                s=mid+1;
            }
            else{ //decreasing slope, search left
                e=mid-1;
            }
        }
        return -1;  
    }
};