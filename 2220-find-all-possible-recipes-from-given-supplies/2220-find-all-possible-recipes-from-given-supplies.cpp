class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>>adj;
        unordered_map<string,int>indegree;

        for(int i=0;i<recipes.size();i++){
            for(auto ing:ingredients[i]){
                adj[ing].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        queue<string>q;
        for(auto &item:supplies){
            q.push(item);
        }
        vector<string>res;
        while(!q.empty()){
            string curr=q.front();
            q.pop();
            for(auto next:adj[curr]){
                indegree[next]--;
                if(indegree[next]==0){
                    res.push_back(next);
                    q.push(next);
                }
            }
        }
        return res;
    }
};