class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());

        for(int i=0;i<n;i++){

            if(i>0 && arr[i]==arr[i-1]){      //i>0 not i>=0 because we are checking i and i-1 value
                continue;                          //ignore duplicate
            }
            int j=i+1;
            int k=n-1;

            while(j<k){
                int sum=arr[i]+arr[j]+arr[k];
                if(sum < 0){
                    j++;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    ans.push_back( {arr[i], arr[j], arr[k]} );
                    j++;
                    k--;

                    while(j<k && arr[j]==arr[j-1]){
                        j++;                                //ignore duplicate
                    }
                }
            }
        }
        return ans;
    }
};
// A set ensures that duplicate triplets are not inserted multiple times.
// Since the order of numbers in a triplet doesn't matter, sorting each triplet before inserting into the set avoids duplicates.

// The final answer must be returned as a vector of vectors, not a set.
// Since a set cannot directly be returned, you copy the unique triplets from set s to ans.