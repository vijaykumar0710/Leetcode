class Solution {
public:
  void dfs(unordered_map<int,vector<int>>&adj,int node,int step,int &cnt,int k,vector<bool>&visited){
   if(step>k) return;
   cnt++;
   visited[node]=true;
   for(auto &v:adj[node]){
    if(!visited[v]){
        dfs(adj,v,step+1,cnt,k,visited);
    }
   }
   visited[node]=false;
  }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        unordered_map<int,vector<int>>adj1,adj2;
        for(auto &edge:edges1){
           adj1[edge[0]].push_back(edge[1]);
           adj1[edge[1]].push_back(edge[0]);
        }
         for(auto &edge:edges2){
           adj2[edge[0]].push_back(edge[1]);
           adj2[edge[1]].push_back(edge[0]);
        }
        int n1=adj1.size(),n2=adj2.size();
         vector<int>v1(n1,0),v2(n2,0);

        for(int i=0;i<n1;i++){
            vector<bool>visited(n1,false);
            int step=0,cnt=0;
            if(k<0) break;
            dfs(adj1,i,step,cnt,k,visited);
            v1[i]=cnt;
        }

          k--;
         for(int i=0;i<n2;i++){
            vector<bool>visited(n2,false);
            int step=0,cnt=0;
            if(k<0) break;
            dfs(adj2,i,step,cnt,k,visited);
            v2[i]=cnt;
        }

        int maximum_v2=*max_element(v2.begin(),v2.end());
        for(int i=0;i<v1.size();i++){
            v1[i]+=maximum_v2;
        }
        return v1;
    }
};