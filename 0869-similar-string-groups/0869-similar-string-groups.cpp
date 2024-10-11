class Solution {
public:
bool isSimilar(string &s1,string &s2){
    int i=0;
    int atmost=0;
    while(i<s1.size()){
        if(s1[i]!=s2[i]) atmost++;
        i++;
    }
    return atmost==0 || atmost==2;
}
void DFS( unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited){
    visited[u]=true;
    for(auto &v:adj[u]){
        if(!visited[v]){
            DFS(adj,v,visited);
        }
    }
}
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(isSimilar(strs[i],strs[j])==true){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool>visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
           if(!visited[i]){
            DFS(adj,i,visited);
            count++;
             }
        }
        return count;
    }
};