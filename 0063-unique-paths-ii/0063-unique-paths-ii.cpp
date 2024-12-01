class Solution {
public:
int t[101][101];
int n,m;
int solve(vector<vector<int>>& grid,int i,int j){
    if(i>=n || j>=m || grid[i][j]==1) return 0;
    if(t[i][j]!=-1) return t[i][j];
     if(i==n-1 && j==m-1) return 1;
    int rightWays=solve(grid,i,j+1);
    int downWays=solve(grid,i+1,j);
    return t[i][j]=rightWays+downWays;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n=obstacleGrid.size();
        m=obstacleGrid[0].size();
        memset(t,-1,sizeof(t));
        return solve(obstacleGrid,0,0);
    }
};