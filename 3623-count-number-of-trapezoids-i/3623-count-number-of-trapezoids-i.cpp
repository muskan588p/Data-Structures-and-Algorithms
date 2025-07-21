class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const long MOD =1e9+7;
        unordered_map<int, int> yc;

        for(auto &p:points){
            yc[p[1]]++;
        }
        
        long totalp=0;
        vector<long> pa;

        for(auto &it: yc){
            if(it.second>=2){
                long c=it.second;
                long p=c*(c-1)/2;
                pa.push_back(p);
                totalp+=p;
            }
        }

        if(totalp<2){
            return 0;
        }

        long total=totalp * (totalp-1)/2;
        for(auto p:pa){
            total-=p * (p-1)/2;
        }
        return (int)(total%MOD);
    }
};