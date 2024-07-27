class Solution {
public:
void dijkstra(char &source,unordered_map<char, vector<pair<char, int>>> &adj,vector<vector<long long>> &costMatrix){
    priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> pq;
    pq.push({0,source});
    while(!pq.empty()){
        int d=pq.top().first;
        char adjChar=pq.top().second;
        pq.pop();

        for(auto &it:adj[adjChar]){
            char adjChar=it.first;
            int cost=it.second;

            if(costMatrix[source-'a'][adjChar-'a']>d+cost){
                costMatrix[source-'a'][adjChar-'a']=d+cost;
                pq.push({d+cost,adjChar});
            }
        }
    }
    return;
}
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<char, int>>> adj;
        for (int i = 0; i < original.size(); i++) {
            char u = original[i];
            char v = changed[i];
            int w = cost[i];
            adj[u].push_back({v, w});
        }
        vector<vector<long long>> costMatrix(26,vector<long long>(26,INT_MAX));
        for(int i=0;i<source.length();i++){
            char ch=source[i];
            dijkstra(ch,adj,costMatrix);
        }
        long long ans=0;
        for(int i=0;i<source.length();i++){
            if(source[i]==target[i]){
                continue;
            }
            if(costMatrix[source[i]-'a'][target[i]-'a']==INT_MAX){
                return -1;
            }
            ans+=costMatrix[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};