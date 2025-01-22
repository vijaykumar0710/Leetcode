class Solution {
public:
vector<int> directions = {-1, 0, 1, 0, -1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n));
        queue<pair<int,int>>que;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    ans[i][j]=-1;
                }else{
                    que.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        while(!que.empty()){
           pair<int,int> curr=que.front();
           int idx=curr.first;
           int jdx=curr.second;
            que.pop();
         for(int i=0;i<4;i++){
            int nextRow=directions[i]+idx;
            int nextCol=directions[i+1]+jdx;
            if(nextRow<m && nextCol<n && nextRow>=0 && nextCol>=0 && ans[nextRow][nextCol]==-1){
                ans[nextRow][nextCol]=ans[idx][jdx]+1;
                que.push({nextRow,nextCol});
            }
         }
        }
        return ans;
    }
};