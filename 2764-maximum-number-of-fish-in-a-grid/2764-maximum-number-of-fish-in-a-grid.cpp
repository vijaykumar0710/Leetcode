class Solution {
public:
int m,n;
int bfs(vector<vector<int>>& grid,int i,int j){
    int count=0;
    queue<pair<int,pair<int,int>>>que;
    que.push({grid[i][j],{i,j}});
    grid[i][j]=0;
    while(!que.empty()){
        int fish=que.front().first;
        int r=que.front().second.first;
        int c=que.front().second.second;
        count+=fish;
        que.pop();
        if(c+1<n && grid[r][c+1]!=0){
            que.push({grid[r][c+1],{r,c+1}});
            grid[r][c+1]=0;
        }
         if(c-1>=0 && grid[r][c-1]!=0){
            que.push({grid[r][c-1],{r,c-1}});
            grid[r][c-1]=0;
        }
         if(r+1<m && grid[r+1][c]!=0){
            que.push({grid[r+1][c],{r+1,c}});
            grid[r+1][c]=0;
        }
         if(r-1>=0 && grid[r-1][c]!=0){
            que.push({grid[r-1][c],{r-1,c}});
            grid[r-1][c]=0;
        }
    }
    return count;
}
    int findMaxFish(vector<vector<int>>& grid) {
         m=grid.size();
         n=grid[0].size();
        int maxi=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    int cnt=bfs(grid,i,j);
                    maxi=max(maxi,cnt);
                }
            }
        }
        return maxi;
    }
};