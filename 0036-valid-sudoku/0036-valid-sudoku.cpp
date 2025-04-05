class Solution {
public:
bool canbevalid(int row,int col,char num,vector<vector<char>>& board){
    for(int  j=0;j<9;j++){
        if(j!=col && board[row][j]==num)
            return false;
    }
    for(int i=0;i<9;i++){
        if(row!=i && board[i][col]==num)
            return false;
    }
    int sr=(row/3)*3;
    int sc=(col/3)*3;
    for(int i=sr;i<sr+3;i++){
        for(int j=sc;j<sc+3;j++){
            if(row!=i && col!=j && board[i][j]==num)
              return false;
        }
    }
    return true;
}
    bool isValidSudoku(vector<vector<char>>& board) {
       for(int i=0;i<9;i++){
           for(int j=0;j<9;j++){
            if(board[i][j]!='.'){ 
              bool res=canbevalid(i,j,board[i][j],board);
              if(res==false) return false;
            }
           }
        }
        return true;
    }
};