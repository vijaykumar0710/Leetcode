class Solution {
public:
int m,n;
int sum;
int maxSum=INT_MIN;
void dfs(vector<vector<int>>& grid,int i,int j){
    if(i<0 || j<0 || i>=m || j>=n || grid[i][j]!=1){
        return;
    }
    if(grid[i][j]=='$'){  
        return;
    }
    
    grid[i][j]='$';   //visited
    
    sum+=1;

    dfs(grid,i+1,j);
    dfs(grid,i,j-1);
    dfs(grid,i,j+1);
    dfs(grid,i-1,j);
} 
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       m=grid.size();
       n=grid[0].size();
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){ 
                sum=0;
                dfs(grid,i,j);
                 maxSum=max(maxSum,sum);
            }
        }
       } 
       
       return maxSum==INT_MIN?0:maxSum;
    }
};