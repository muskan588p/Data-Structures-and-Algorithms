class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n=arr.size();
        int count=0;
        vector<int> prefixsum(n,0);
        unordered_map<int,int> m;   //pfsum, freq
        
        prefixsum[0]=arr[0];   //first ele is same
        for(int i=1;i<n;i++){      //start from i=1 as 0 ele is same
            prefixsum[i]=prefixsum[i-1]+arr[i];
        }

        for(int j=0;j<n;j++){
            if(prefixsum[j] == k){
                count++;
            }
            int val=prefixsum[j] - k;   //ps[i-1]=ps[j]-k
            if(m.find(val) != m.end()){   //if val exists
                count += m[val];       //add the freq for the val ps[i-1]
            }

            if(m.find(prefixsum[j]) == m.end()){   //if not exists store in map with freq
                m[prefixsum[j]] = 0;
            }
            m[prefixsum[j]]++;
        }
        return count;
    }
};