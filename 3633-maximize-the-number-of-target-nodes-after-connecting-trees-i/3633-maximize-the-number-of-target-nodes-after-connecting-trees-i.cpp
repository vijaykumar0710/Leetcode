class Solution {
public:
vector<int> countReachableWithinK(unordered_map<int,vector<int>>& adj, int k) {
    int n = adj.size();
    vector<int> result(n,0);

   if(k<0) return result;

    for (int start = 0; start < n; start++) {
        vector<bool> visited(n, false);
        queue<pair<int, int>> q; // (node, steps)
        visited[start] = true;
        q.push({start, 0});

        int count = 1; // count itself

        while (!q.empty()) {
            auto [node, steps] = q.front();
            q.pop();

            if (steps == k) continue;

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, steps + 1});
                    count++;
                }
            }
        }
        result[start] = count;
    }

    return result;
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
        vector<int>v1=countReachableWithinK(adj1,k);
        vector<int>v2=countReachableWithinK(adj2,k-1);
        int maximum_v2=*max_element(v2.begin(),v2.end());
        for(int i=0;i<v1.size();i++){
            v1[i]+=maximum_v2;
        }
        return v1;
    }
};