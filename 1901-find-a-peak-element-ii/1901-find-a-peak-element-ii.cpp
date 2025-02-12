class Solution {
public:
    int maxele(vector<vector<int>>& mat, int n, int m, int col){
        int maxvalue=-1;
        int idx=-1;
        for(int i=0;i<m;i++){
            if(mat[i][col] > maxvalue){
                maxvalue=mat[i][col];
                idx=i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();            //mat[0] not mat[i]
        int l=0;
        int h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            int row=maxele(mat,n,m,mid);     //max row index which has largest value
            int left= mid-1 >= 0  ? mat[row][mid-1]  : -1;
            int right= mid+1 < n  ? mat[row][mid+1]  : -1;

            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row, mid};
            }
            else if(mat[row][mid] < left){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return {-1,-1};
    }
};