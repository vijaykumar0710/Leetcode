class Solution {
public:
int m,n;
void dfs(vector<vector<char>>& grid,int i,int j){
    if(i<0 || j<0 || i>=m || j>=n || grid[i][j]!='1'){
        return;
    }
    if(grid[i][j]=='$'){  //visited
        return;
    }
    grid[i][j]='$';
    
    dfs(grid,i+1,j);
    dfs(grid,i,j-1);
    dfs(grid,i,j+1);
    dfs(grid,i-1,j);
} 
    int numIslands(vector<vector<char>>& grid) {
       m=grid.size();
       n=grid[0].size();
       int islands=0;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){
                dfs(grid,i,j);
                islands++;
            }
        }
       } 
       return islands;
    }
};