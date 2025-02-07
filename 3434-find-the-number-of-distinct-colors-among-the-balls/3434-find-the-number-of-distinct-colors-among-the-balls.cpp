class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n=queries.size();
        unordered_map<long,long>ballmp;
        unordered_map<long,long>colormp;
        vector<int>result;
        for(auto &query:queries){
            int ball=query[0];
            int color=query[1];
            if(ballmp.count(ball)){
                colormp[ballmp[ball]]--;
                if(colormp[ballmp[ball]]==0){
                  colormp.erase(ballmp[ball]);
                }
            }
            ballmp[ball]=color;
            colormp[color]++;
            result.push_back(colormp.size());
        }
        return result;
    }
};