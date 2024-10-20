class Solution {
public:
int k=0;
  void DFS(unordered_map<int,vector<int>>&adj,int root,vector<bool>&visited){
   visited[root]=true;
   k++;
   for(auto &v:adj[root]){
      if(!visited[v]){
        DFS(adj,v,visited);
      }
   }
  }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            int left=leftChild[i];
            int right=rightChild[i];
           if(left!=-1) adj[i].push_back(left);
           if(right!=-1) adj[i].push_back(right);
        }
        vector<int>parent(n,-2);
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1){
                int x=leftChild[i];
              if(parent[x]==-2){
                parent[x]=i;
              }else{
                return false;
              }
            }
            if(rightChild[i]!=-1){
                int y=rightChild[i];
                if(parent[y]==-2){
                    parent[y]=i;
                }else{
                    return false;
                }
            }
        }
        int root=-3;
       for(int i=0;i<n;i++){
        if(parent[i]==-2){
          root=i;
        }
       }
          if(root==-3) return false;

          vector<bool>visited(n,false);
           DFS(adj,root,visited);
           if(k!=n)return false;
           return true;
    }
};