class Solution {
public:
typedef long long ll;
const int LARGE_VALUE=2e9;
typedef pair<long,long>p;

ll DijkstraAlgo(vector<vector<int>>& edges,int n,int src,int dest){
    unordered_map<ll,vector<pair<ll,ll>>> adj;

    for(vector<int>&edge:edges){
        if(edge[2]!=-1){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
    }
        priority_queue<p,vector<p>,greater<p>> pq;
        vector<ll> result(n,INT_MAX);
        vector<bool> visited(n,false);

        result[src]=0;
        pq.push({0,src});

        while(!pq.empty()){
            ll currDist=pq.top().first;
            ll currNode=pq.top().second;
            pq.pop();

            if(visited[currNode]==true){
                continue;
            }
            visited[currNode]=true;
            for(auto&[ngbr,wt]:adj[currNode]){
             if(result[ngbr]>currDist+wt){ 
                result[ngbr]=currDist+wt;
                pq.push({result[ngbr],ngbr});
               }
            }
        }
        return result[dest];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        ll currShortestDist=DijkstraAlgo(edges,n,source,destination);

    if(currShortestDist<target) return {};

        bool matchedTarget=(currShortestDist==target);

        if(matchedTarget==true){
            for(vector<int>& edge:edges){
                 if(edge[2]==-1){
                    edge[2]=LARGE_VALUE;
                 }
            }
            return edges;
        }
        for(vector<int>& edge:edges){
            if(edge[2]==-1){
                edge[2]=(matchedTarget==true)?LARGE_VALUE:1;
                if(matchedTarget!=true){
                    ll newShortestDist=DijkstraAlgo(edges,n,source,destination);

                    if(newShortestDist<=target){
                    matchedTarget=true;
                    edge[2]+=(target-newShortestDist);
                    }
                }
            }
        }
        if(matchedTarget==false){
            return {};
        }
        return edges;
    }
};