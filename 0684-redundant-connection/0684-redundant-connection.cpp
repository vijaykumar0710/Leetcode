class Solution {
public:
    vector<int> parent, rank;
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);  // Path compression
    }
    bool Union(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) return true;  // Cycle detected
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        vector<vector<int>>res;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            if(find(u)==find(v)){
              res.push_back({u,v});
            }else{
                Union(u,v);
            }
        }
        return res.back();
    }
};
