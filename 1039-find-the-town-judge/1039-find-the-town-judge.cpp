class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int>mp;
        vector<int>indegree(n+1,0);
        for(auto &trusts:trust){
          mp[trusts[0]]=trusts[1];
          indegree[trusts[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(mp.find(i)==mp.end() && indegree[i]==n-1){ 
                return i;
        }
        }
        return -1;
    }
};