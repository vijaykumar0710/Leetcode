class Solution {
public:
int m;
int n;
void solver(vector<vector<char>>& grid,int i,int j){
    if(i<0 || i>=m ||j<0 || j>=n || grid[i][j]!='1'){
        return;
    }
    if(grid[i][j]=='2') return;

    grid[i][j]='2';

    solver(grid,i,j+1);
    solver(grid,i,j-1);
    solver(grid,i-1,j);
    solver(grid,i+1,j);
}
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    solver(grid,i,j);
                    count++;
                }      
            }
        }
        return count;
    }
};