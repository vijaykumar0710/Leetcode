class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &flight:flights){
            int u=flight[0];
            int v=flight[1];
            int w=flight[2];
            adj[u].push_back({v,w});
        }
        queue<pair<int,int>>pq;
        vector<int>result(n,INT_MAX);
        result[src]=0;
        pq.push({0,src});
        int steps=0;
        while(!pq.empty() && steps<=k){
            int sz=pq.size();
            while(sz--){ 
            int d=pq.front().first;
            int node=pq.front().second;
            pq.pop();
    
        for(auto &vec:adj[node]){
            int adjNode=vec.first;
            int dist=vec.second;
            if(d+dist<result[adjNode]){
                result[adjNode]=d+dist;
                pq.push({d+dist,adjNode});
               }
             }
           }
           steps++;
        }
        return result[dst]!=INT_MAX?result[dst]:-1;
    }
};