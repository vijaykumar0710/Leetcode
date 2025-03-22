class Solution {
public:
vector<int>rank;
vector<int>parent;
int find(int x){
    if(x==parent[x])
      return x;
    return parent[x]=find(parent[x]);
}
void Union(int x,int y){
    int parent_x=find(x);
    int parent_y=find(y);

    if(parent_x==parent_y)
       return;
    
    if(rank[parent_x]>rank[parent_y]){
        parent[parent_y]=parent_x;
    }else if(rank[parent_x]<rank[parent_y]){
        parent[parent_x]=parent_y;
    }else{
        parent[parent_y]=parent_x;
        rank[x]++;
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n,0);
      for(int i=0;i<n;i++){
        parent[i]=i;
      }
     for(auto &edge:edges){
        int u=edge[0];
        int v=edge[1];
        Union(u,v);
     }
     unordered_map<int,int>nodeCnt,edgeCnt;
     for(int i=0;i<n;i++){
        int parent=find(i);
        nodeCnt[parent]++;
     }
     for(auto &edge:edges){
        int u=edge[0];
        int v=edge[1];
        int p=find(u);
        edgeCnt[p]++;
     }
     int cnt=0;
     for(auto &poi:nodeCnt){
        int p=poi.first;
        int nodes=poi.second;
        int edges=edgeCnt[p];
        if(edges==nodes*(nodes-1)/2){
            cnt++;
        }
     }
    return cnt;
    }
};