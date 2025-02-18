class Solution {
public:
    bool issafe(vector<string> &board, int row, int col, int n){
        //horizontal
        for(int j=0;j<n;j++){
            if(board[row][j]=='Q'){
                return false;
            }
        }
        //vertical
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        //left diagonal
        for(int i=row, j=col; i>=0 && j>=0 ; i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        //right diagonal
        for(int i=row, j=col; i>=0 && j<=n; i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void nqueens(vector<string> &board, int row, int n, vector<vector<string>> &ans){
        //base case
        if(row==n){
            ans.push_back({board});
            return;
        }

        for(int j=0;j<n;j++){
            if(issafe(board,row,j,n)){
                board[row][j]='Q';
                nqueens(board,row+1,n,ans);

                board[row][j]='.';           //backtrack
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        nqueens(board,0,n,ans);        //starts from 0th row

        return ans;
    }
};