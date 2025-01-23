class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int total=0;
        stack<pair<int,int>>st;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    total++;
                    st.push({i,j});
                }
            }
        }
            int cnt=0;
            while(!st.empty()){
                int row=st.top().first;
                int col=st.top().second;
                st.pop();
                bool flag=false;
                for(int i=0;i<n;i++){
                    if(i!=col && grid[row][i]==1){
                        flag=true;
                        break;
                    }
                }
                bool flag2=false;
                for(int j=0;j<m;j++){ 
                   if(j!=row && grid[j][col]==1){
                        flag2=true;
                        break;
                    }
                }
                if(flag==false && flag2==false){
                    cnt++;
                }
            }
        return total-cnt;
    }
};