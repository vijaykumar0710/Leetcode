class Solution {
public:
vector<int>parent,rank;
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
    }else if(rank[parent_y]>rank[parent_x]){
        parent[parent_x]=parent_y;
    }else{
        parent[parent_y]=parent_x;
        rank[parent_x]++;
    }
}
    int minSwapsCouples(vector<int>& row) {
        int n=row.size()/2;
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<row.size();i+=2){
            int a=row[i]/2;
            int b=row[i+1]/2;
            Union(a,b);
        }
        unordered_map<int,int>count;
        for(int i=0;i<n;i++){
            int root=find(i);
            count[root]++;
        }
        int swaps=0;
        for(auto &it:count){
            swaps+=it.second-1;
        }
        return swaps;
    }
};