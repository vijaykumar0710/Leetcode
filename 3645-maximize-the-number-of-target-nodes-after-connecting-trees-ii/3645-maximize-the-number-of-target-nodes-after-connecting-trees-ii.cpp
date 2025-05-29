class Solution {
public:
void bfs(vector<vector<int>>&adj,int node,int n,vector<int>&v){
    vector<bool>visited(n,false);
    queue<pair<int,int>>q;
    q.push({node,0});
    visited[node]=true;
    while(!q.empty()){
        auto [node,level]=q.front();
        if(level%2==0) v[node]=0;
        else v[node]=1;
        q.pop();
        for(auto &v:adj[node]){
            if(!visited[v]){
                visited[v]=true;
                q.push({v,level+1});
            }
        }
    }
}

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1=edges1.size()+1,n2=edges2.size()+1;
        vector<vector<int>>adj1(n1),adj2(n2);
        for(auto &edge:edges1){
            int u=edge[0],v=edge[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
         for(auto &edge:edges2){
            int u=edge[0],v=edge[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        vector<int>v1(n1),v2(n2);
    
        bfs(adj1,0,n1,v1);
        bfs(adj2,0,n2,v2);
        
        int even_v1=0,odd_v1=0;
        for(auto &num:v1){
            if(num==0) even_v1++;
            else odd_v1++;
        }

        int even_v2=0,odd_v2=0;
         for(auto &num:v2){
            if(num==0) even_v2++;
            else odd_v2++;
        }
        int maxi=max(even_v2,odd_v2);
        vector<int>res(n1);
        for(int i=0;i<n1;i++){
            if(v1[i]==0) res[i]=even_v1+maxi;
            else res[i]=odd_v1+maxi;
        }
        return res;
    }
};