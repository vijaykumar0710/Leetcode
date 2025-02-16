class Solution {
public:
int m,n;
int res;
vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
void backtrack(vector<vector<int>>& grid,int i,int j,int sum){
    if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0){
           res=max(res,sum);
           return;
    }
    int gold=grid[i][j];
        sum+=gold;
        grid[i][j]=0;
    for(auto &dir:directions){
        int x=i+dir[0];
        int y=j+dir[1];
        backtrack(grid,x,y,sum);
    }
    grid[i][j]=gold;
}
    int getMaximumGold(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              if(grid[i][j]!=0){
                backtrack(grid,i,j,0);
               } 
            }
        }
        return res;
    }
};