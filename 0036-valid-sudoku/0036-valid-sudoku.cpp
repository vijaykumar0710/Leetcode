class Solution {
public:
bool traversal(vector<vector<char>>& board,int sr,int er,int sc,int ec){
    unordered_set<char>sub_box;
    for(int i=sr;i<=er;i++){
            for(int j=sc;j<=ec;j++){
                int num=board[i][j];
                if(num=='.') continue;
                if(sub_box.find(num)!=sub_box.end()){
                    return false;
                }
                sub_box.insert(num);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        // check row
        for(int row=0;row<9;row++){
            unordered_set<char>rows;
            for(int col=0;col<9;col++){
                int num=board[row][col];
                if(num=='.') continue;
                if(rows.find(num)!=rows.end()){
                    return false;
                }
                rows.insert(num);
            }
        }
           // check column
        for(int col=0;col<9;col++){
            unordered_set<char>cols;
            for(int row=0;row<9;row++){
                int num=board[row][col];
                if(num=='.') continue;
                if(cols.find(num)!=cols.end()){
                    return false;
                }
                cols.insert(num);
            }
        }
            // check sub-box
            for(int sr=0;sr<9;sr+=3){
                int er=sr+2;
                for(int sc=0;sc<9;sc+=3){
                    int ec=sc+2;
                    if(!traversal(board,sr,er,sc,ec)){
                        return false;
                    }
                }
            }
            return true;
    }
};