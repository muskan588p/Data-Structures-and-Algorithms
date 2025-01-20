class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int sr=0;
        int er=m-1;

        int n=mat[0].size();
        int sc=0;
        int ec=n-1;

        vector<int> ans;

        while(sr<=er && sc<=ec){
            //top
            for(int j=sc; j<=ec; j++){
                ans.push_back(mat[sr][j]);
            }
            //right
            for(int i=sr+1; i<=er; i++){
                ans.push_back(mat[i][ec]);
            }
            //bottom
            for(int j=ec-1; j>=sc; j--){
                if(sr==er){               //corner case for odd row
                    break;
                }
                ans.push_back(mat[er][j]);
            }
            //left
            for(int i=er-1; i>=sr+1; i--){
                if(sc==ec){               //corner case for odd column
                    break;
                }
                ans.push_back(mat[i][sc]);
            }
            sr++; er--;
            sc++; ec--;
        }
        return ans;
    }
};