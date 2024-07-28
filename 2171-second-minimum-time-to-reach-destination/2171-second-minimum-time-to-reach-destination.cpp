class Solution {
public:
#define p pair<int,int>
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        unordered_map<int,vector<int>> adj;

        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> d1(n+1,INT_MAX);  //first minimum
        vector<int> d2(n+1,INT_MAX);  //second minimum
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,1});
        d1[1]=0;

        while(!pq.empty()){
            auto[timePassed,node]=pq.top();
            pq.pop();

            if(node==n && d2[n]!=INT_MAX){  //check whether we reach at destination
            return d2[n];
            }
             int div=timePassed/change;
             if(div%2==1){   //red wala region me hu
                 timePassed=(div+1)*change;
             }
             for(auto &nbr:adj[node]){
              if(d1[nbr]>timePassed+time){
                d2[nbr]=d1[nbr];
                d1[nbr]=timePassed+time;
                pq.push({timePassed+time,nbr});
              }else if(d2[nbr]>timePassed+time && d1[nbr]!=timePassed+time){
                d2[nbr]=timePassed+time;
                pq.push({timePassed+time,nbr});
                }
            }
        }
        return -1;
    }
};