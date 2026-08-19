class Solution {
private:
    bool issafe(char val,int row,int col,vector<vector<char>>&board){
        for(int i = 0; i < 9; i++) {
            if(i != col && board[row][i] == val)
                return false;
            if(i != row && board[i][col] == val)
                return false;
        }
        int startRow = 3 * (row / 3);
        int startCol = 3 * (col / 3);
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                int r = startRow + i;
                int c = startCol + j;
                if((r != row || c != col) && board[r][c] == val)
                    return false;
            }
        }

        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row=0;row<board.size();row++){
            for(int col=0;col<board.size();col++){
                if(board[row][col]!='.'){
                    if(!issafe(board[row][col],row,col,board)){
                            return false;
                    }
                }
            }
        }
        return true;
    }
};