class Solution {
public:
    bool search(vector<vector<int>>& mat, int target, int row){ //log(n)
        int n=mat[0].size();
        
        for (int col = 0; col < n; col++) {
            if (mat[row][col] == target) {
                return true;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) { //log(m)
        int m=mat.size();
        int n=mat[0].size();

        int sr=0;
        int er=m-1;
        while(sr <= er){
            int midrow=sr+(er-sr)/2;
            if(mat[midrow][0] <= target && target <= mat[midrow][n-1]){
                return search(mat, target, midrow);
            }
            else if(target >= mat[midrow][n-1]){
                sr=midrow+1;
            }
            else if(target <= mat[midrow][0]){
                er=midrow-1;
            }
        }
        return false;
    }
};