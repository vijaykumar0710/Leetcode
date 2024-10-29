class Solution {
public:
int m,n;
int t[1001][1001];
int helper(vector<vector<int>>&grid,int i,int j){
    if(i<0 || i>=m || j<0 ||j>=n) return 0;
    int cnt1=0;
    int cnt2=0;
    int cnt3=0;
    if(t[i][j]!=-1) return t[i][j];
    if(i>0 && j+1<n && grid[i][j]<grid[i-1][j+1]){
        cnt1=1+helper(grid,i-1,j+1);
    }
    if(j+1<n && grid[i][j]<grid[i][j+1]){
        cnt2=1+helper(grid,i,j+1);
    }
    if(i+1<m && j+1<n && grid[i][j]<grid[i+1][j+1]){
        cnt3=1+helper(grid,i+1,j+1);
    }
    return t[i][j]=max({cnt1,cnt2,cnt3});
}
    int maxMoves(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int maxcnt=-1;
        for(int i=0;i<m;i++){
            memset(t,-1,sizeof(t));
            int count=helper(grid,i,0);
            maxcnt=max(maxcnt,count);
        }
        return maxcnt;
    }
};