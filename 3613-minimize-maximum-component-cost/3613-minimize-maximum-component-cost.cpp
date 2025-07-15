class Solution {
public:
    class DSU{
        public:
            vector<int> p, ra;
            DSU(int n){
                p.resize(n);
                ra.resize(n,0);
                for(int i=0;i<n;i++){
                    p[i]=i;
                }
            }
            int find(int x){
                    if(p[x]!=x){
                        p[x]=find(p[x]);
                    }
                    return p[x];
                }
        
                bool un(int x, int y){
                    int xr=find(x);
                    int yr=find(y);
                    if(xr==yr){
                        return false;
                    }
                    if(ra[xr] < ra[yr]){
                        p[xr]=yr;
                    }
                    else if(ra[yr]<ra[xr]){
                        p[yr]=xr;
                    }
                    else{
                        p[yr]=xr;
                        ra[xr]++;
                    }
                    return true;
                }
            };
            int minCost(int n, vector<vector<int>>& edges, int k) {
                sort(edges.begin(), edges.end(), [](vector<int> & a, vector<int> &b){
                    return a[2]<b[2];
                });
        
                DSU dsu(n);
                priority_queue<int> maxe;
        
                for(auto &e: edges){
                    int u=e[0];
                    int v=e[1];
                    int w=e[2];
        
                    if(dsu.un(u, v)){
                        maxe.push(w);
                    }
                }
        
                for(int i=0;i<k-1 && !maxe.empty(); i++){
                    maxe.pop();
                }
                return maxe.empty() ? 0 : maxe.top();
    
    
    }
};