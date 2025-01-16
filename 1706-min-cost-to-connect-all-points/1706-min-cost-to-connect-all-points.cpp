class Solution {
public:
typedef pair<int,int>p;
int minMST(vector<vector<p>>& adj,int v){
    priority_queue<p,vector<p>,greater<p>>pq;
    pq.push({0,0}); //{weight,vertex}
    vector<bool>inMST(v,false);
    int sum=0;
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        int wt=p.first;
        int node=p.second;
        if(inMST[node]==true){
            continue;
        }
       inMST[node]=true;
       sum+=wt;
       for(auto &tmp:adj[node]){
        int neigh=tmp.first;
        int neigh_wt=tmp.second;
        if(!inMST[neigh]){
            pq.push({neigh_wt,neigh});
        }
       }
    }
    return sum;
}
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v=points.size();
        vector<vector<p>>adj(v);
        for(int i=0;i<v;i++){
            for(int j=i+1;j<v;j++){
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                int d=abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({j,d});
                adj[j].push_back({i,d});
            }
        }
        return minMST(adj,v);
    }
};