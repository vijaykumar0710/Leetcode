class Solution {
public:
vector<pair<int,int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
int find(vector<int>&parent,int x){
    if(x==parent[x])
      return x;
   return parent[x]=find(parent,parent[x]);
}
void Union(vector<int>&parent,vector<int>&rank,int x,int y){
    int parent_x=find(parent,x);
    int parent_y=find(parent,y);
    if(parent_x==parent_y) return;
    if(rank[parent_x]>rank[parent_y]){
        parent[parent_y]=parent_x;
    }
    else if(rank[parent_y]>rank[parent_x]){
        parent[parent_x]=parent_y;
    }
    else{
         parent[parent_x]=parent_y;
         rank[parent_y]++;
    }
}
int getId(int i,int j,int cols){
    return i*cols+j; //gives 1D index
}
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int n=rows*cols;
        vector<int>rank(n,0);
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
               if(grid[i][j]=='1'){
                for(auto &[di,dj]:directions){
                    int ni=i+di;
                    int nj=j+dj;
                    if(ni>=0 && ni<rows && nj>=0 && nj<cols && grid[ni][nj]=='1'){
                        int id1=getId(i,j,cols);
                        int id2=getId(ni,nj,cols);
                        Union(parent,rank,id1,id2);
                    }
                 }
               }
            }
        }

        unordered_set<int>uniqueComponenets;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                  int id=getId(i,j,cols);
                  uniqueComponenets.insert(find(parent,id));
                }
            }
        }
        return uniqueComponenets.size();
    }
};