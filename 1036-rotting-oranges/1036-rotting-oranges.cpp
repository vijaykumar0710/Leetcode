class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int total_oranges=0;
          int rotten_oranges=0;
          int days=0;
        if(grid.empty()) return 0;
        queue<pair<int,int>>rotten;
      for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0) total_oranges++;
                if(grid[i][j]==2) rotten.push({i,j});
            }
        }
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};

          while(!rotten.empty()){
            int k=rotten.size();
            rotten_oranges+=k;
            while(k--){
                int x=rotten.front().first;
                int y=rotten.front().second;
                rotten.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny]!=1) continue;
                    grid[nx][ny]=2;
                    rotten.push({nx,ny});
                }
              }
              if(!rotten.empty()) days++;
          }
          return total_oranges==rotten_oranges?days:-1;
    }
};