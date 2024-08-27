class Solution {
public:
double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>>adj;
         for(int idx=0;idx<edges.size();idx++){
             int x=edges[idx][0];
             int y=edges[idx][1];
             double z=succProb[idx];
             adj[x].push_back({y,z});
             adj[y].push_back({x,z});
         }
         priority_queue<pair<double,int>>pq;
          vector<double> maxProb(n, 0.0);
          maxProb[start_node] = 1.0;

          pq.push({1.0,start_node});

          while(!pq.empty()){
           auto[prob,node]=pq.top();
            pq.pop();

            if(node==end_node){
                return prob;
            }
            for(auto &[v,edgeprob]:adj[node]){
                  double newProb=prob*edgeprob;
                  if(newProb>maxProb[v]){
                maxProb[v]=newProb;
                pq.push({newProb,v});
              }
            }
          }
          return 0.0;
    }
};