class Solution {
public:
    static bool cmp(vector<int> &a, vector<int>&b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int count=0;
        int prevend=INT_MIN;  //not 0 becuase -ve no.s 

        int n=intervals.size();

        for(int i=0;i<n;i++){
            if(prevend <= intervals[i][0]){  // <= becuase = is allowed
                prevend=intervals[i][1];
            }
            else{
                count++;
            }
        }
        return count;
    }
};