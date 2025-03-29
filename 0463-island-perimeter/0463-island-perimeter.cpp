class Solution {
public:
vector<vector<int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
int dfs(vector<vector<int>>& grid,int m,int n,int row,int col,vector<vector<int>>&visited,int &res){
 if(row<0 || row>=m || col<0 || col>=n || visited[row][col]==2)
      return 0;
if(grid[row][col]!=1)
   return 0;
visited[row][col]=2;
int cnt=0;
for(auto &dir:directions){
    int adjRow=row+dir[0];
    int adjCol=col+dir[1];
    if(adjRow>=0 && adjRow<m && adjCol>=0 && adjCol<n){ 
    if(grid[adjRow][adjCol]==1){
        cnt++;
      }
    }
  }
  res+=(4-cnt);
  for(auto &dir:directions){
    int newRow=row+dir[0];
    int newCol=col+dir[1];
   dfs(grid,m,n,newRow,newCol,visited,res);
  }
  return res;
}
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int res=0;
        int row,col;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                  row=i,col=j;
                  break;
                }
            }
        }
        return dfs(grid,m,n,row,col,visited,res);
    }
};