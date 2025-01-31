class Solution {
public:
int n;
   vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
   int DFS(vector<vector<int>>& grid,int i,int j,int &id){
    if(i<0 || i>=n || j<0 || j>=n || grid[i][j]!=1)
        return 0;
    
    grid[i][j]=id;
    int count=1;
     for(vector<int>&dir:directions){
        int x_=i+dir[0];
        int y_=j+dir[1];
        count+=DFS(grid,x_,y_,id);
     }
     return count;
   }
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        int maxArea=0;
        unordered_map<int,int>mp;
        int island_id=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int size=DFS(grid,i,j,island_id);
                    maxArea=max(maxArea,size);
                    mp[island_id]=size;
                    island_id++;
                }
            }
        }
   for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0){
              unordered_set<int>st;
              for(auto &dir:directions){
                int x=i+dir[0];
                int y=j+dir[1];
                if(x>=0 && x<n && y>=0 && y<n && grid[x][y]!=0)
                    st.insert(grid[x][y]);
              }
              int overAllSize=1;
              for(const int &s:st){
                overAllSize+=mp[s];
              }
              maxArea=max(maxArea,overAllSize);
            }
          }
       }
       return maxArea;
    }
};