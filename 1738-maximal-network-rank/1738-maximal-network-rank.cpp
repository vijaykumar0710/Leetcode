class Solution {
public:
typedef pair<int,int>p;
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
     vector<int>indegree(n,0);
     vector<vector<bool>>isConnected(n,vector<bool>(n,false));
      for(auto &road:roads){
        int u=road[0];
        int v=road[1];
        indegree[u]++;
        indegree[v]++;
        isConnected[u][v]=true;
        isConnected[v][u]=true;
      }
      int maxRank=0;
      for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int network=indegree[i]+indegree[j];
            if(isConnected[i][j]){
                network--;
            }
             maxRank=max(maxRank,network);
        }
      }
      return maxRank;
    }
};