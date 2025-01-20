class Solution {
public:
int n;
int t[201][201];
int solve(vector<vector<int>>& triangle,int i,int j){
    if(i==n-1) return triangle[n-1][j];
    if(t[i][j]!=-1) return t[i][j];
    int down=triangle[i][j]+solve(triangle,i+1,j);
    int diagonal=triangle[i][j]+solve(triangle,i+1,j+1);
    return t[i][j]=min(down,diagonal);
}
    int minimumTotal(vector<vector<int>>& triangle) {
       n=triangle.size();
       memset(t,-1,sizeof(t));
       return solve(triangle,0,0);
    }
};