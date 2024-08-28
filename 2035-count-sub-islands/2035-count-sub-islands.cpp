class Solution {
public:
bool dfs(int i,int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2){
    if(i<0 || j<0 || i>=grid2.size() || j>=grid2[0].size()){
        return true;
    }
    if(grid2[i][j]!=1) return true;

         grid2[i][j]=-1;  
         
      bool result=(grid1[i][j]==1);

      result=result & dfs(i+1,j,grid1,grid2);
      result=result & dfs(i-1,j,grid1,grid2);
      result=result & dfs(i,j+1,grid1,grid2);
      result=result & dfs(i,j-1,grid1,grid2);

      return result;
}
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int subIslands=0;
        int m=grid2.size();
        int n=grid2[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1 ){
                 if(dfs(i,j,grid1,grid2)){
               subIslands++;
                  }
                }
            }
        }
        return subIslands;
    }
};