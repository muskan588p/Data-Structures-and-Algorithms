class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n=arr.size();
        int piv=-1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                piv=i;
                break;
            }
        }
        if(piv==-1){
            reverse(arr.begin(), arr.end());
            return;
        }
        //next larger ele
        for(int i=n-1;i>piv;i--){
            if(arr[i]>arr[piv]){
                swap(arr[i], arr[piv]);
                break;             //ek baar hi swap krna hai jo next large ele hai 
            }                      //nhi toh saare hojenge swap
        }
        //reverse piv+1 to n-1
        int i=piv+1;
        int j=n-1;
        while(i<=j){
            swap(arr[i], arr[j]);
                i++;
                j--;
        }
    }
};