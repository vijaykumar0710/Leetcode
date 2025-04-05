class Solution {
public:
bool canbePlace(int row,int col,char num,vector<vector<char>>& board){
    for(int j=0;j<9;j++){
       if(board[row][j]==num)
        return false;
    }
    for(int i=0;i<9;i++){
       if(board[i][col]==num)
        return false;
    }
    int sr=(row/3)*3;
    int sc=(col/3)*3;
    for(int i=sr;i<sr+3;i++){
        for(int j=sc;j<sc+3;j++){
            if(board[i][j]==num)
                return false;
        }
    }
    return true;
}
bool helper(int row,int col,vector<vector<char>>& board){
    if(row==9) return true;
    if(col==9){
        return helper(row+1,0,board);
    }

    if(board[row][col]!='.'){
        return helper(row,col+1,board);
    }

   for(char num='1';num<='9';num++){
    if(canbePlace(row,col,num,board)){
       board[row][col]=num;
       bool res=helper(row,col+1,board);
       if(res==true) return true;
     }
   }
   board[row][col]='.';
   return false;
}
    void solveSudoku(vector<vector<char>>& board) {
     helper(0,0,board);
    }
};