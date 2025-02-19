class Solution {
public:
    bool issafe(vector<vector<char>>& board, int row, int col, char dig){
        //horizontal
        for(int j=0;j<9;j++){
            if(board[row][j]==dig){
                return false;
            }
        }
        //vertical
        for(int i=0;i<9;i++){
            if(board[i][col]==dig){
                return false;
            }
        }
        //grid
        int sr=(row/3)*3;
        int sc=(col/3)*3;
        for(int i=sr;i<=sr+2;i++){
            for(int j=sc;j<=sc+2;j++){
                if(board[i][j]==dig){
                    return false;
                }
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>& board, int row, int col){
        //base case
        if(row==9){
            return true;
        }

        int nextr=row;
        int nextc=col+1;
        if(nextc == 9){
            nextr=row+1;
            nextc=0;
        }

        if(board[row][col] != '.'){
            return helper(board, nextr, nextc);
        }

        for(char dig='1'; dig<='9'; dig++){
            if(issafe(board, row, col, dig)){
                board[row][col]=dig;          //place the digit
                if(helper(board, nextr, nextc)){
                    return true;
                }
                board[row][col]='.';           //backtrack and replace dig back to dot
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);       //start row and col at 0 idx
    }
};