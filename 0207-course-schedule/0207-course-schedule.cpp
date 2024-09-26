class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(n,0);
        for(auto &num:prerequisites){
            int a=num[0];
            int b=num[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int>que;
        int count=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                count++;
                que.push(i);
                }
        }
        while(!que.empty()){
          int u=que.front();
          que.pop();
          for(int &v:adj[u]){
            indegree[v]--;
            if(indegree[v]==0){
                count++;
                que.push(v);
              }
           }
        }
        return count==n;
    }
};