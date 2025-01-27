class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(numCourses, 0);
        for (auto& pre : prerequisites) {
            adj[pre[0]].push_back(pre[1]);
            inDegree[pre[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) q.push(i);
        }
       unordered_map<int,unordered_set<int>>topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int neighbor : adj[node]) {
                topo[neighbor].insert(node);
                for(auto &prereq:topo[node]){
                    topo[neighbor].insert(prereq);
                }
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) q.push(neighbor);
            }
        }
       vector<bool>result;
       for(auto query:queries){
        int a=query[0];
        int b=query[1];
        bool isReachable=topo[b].contains(a);
        result.push_back(isReachable);
       }
       return result;
    }
};