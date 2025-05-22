class Solution {
public:
vector<vector<int>>dirs={{0,1},{0,-1},{1,0},{-1,0}};
bool solve(vector<vector<char>>& board, string word,int row,int col,int idx,int m,int n,vector<vector<bool>>&visited){
if(idx==word.size()) return true;
if(row<0 || row>=m || col<0 || col>=n || visited[row][col] || board[row][col]!=word[idx]) return false;

visited[row][col]=true;

for(auto &dir:dirs){
    int n_r=row+dir[0];
    int n_c=col+dir[1];
    if(solve(board,word,n_r,n_c,idx+1,m,n,visited))
        return true;
  }
visited[row][col]=false;
  return false;
}
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){ 
                if(solve(board,word,i,j,0,m,n,visited))
                   return true;
                }
            }
        }
        return false;
    }
};