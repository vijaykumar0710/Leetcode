class Solution {
public:
bool DFS(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited,stack<int>&st,vector<bool>&inRecursion){
    visited[u]=true;
    inRecursion[u]=true;
    for(int &v:adj[u]){
        if(!visited[v]){
           if(DFS(adj,v,visited,st,inRecursion)){
            return true;
           }
           }else if(inRecursion[v]){
              return true;
        }
    }
    inRecursion[u]=false;
    st.push(u);
    return false;
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        unordered_map<int,vector<int>>adj;
        for(auto &num:prerequisites){
            int a=num[0];
            int b=num[1];
            adj[b].push_back(a);
        }
        vector<bool>visited(n,false);
        vector<bool>inRecursion(n,false);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(DFS(adj,i,visited,st,inRecursion)){
                    return {};
                }
            }
        }
        vector<int>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};