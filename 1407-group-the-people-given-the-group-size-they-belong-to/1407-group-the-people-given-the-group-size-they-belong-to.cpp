class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>>mp;
        int n=groupSizes.size();
        for(int i=0;i<n;i++){
            mp[groupSizes[i]].push_back(i);
        }
     vector<vector<int>>result;
     for(auto &[size,indices]:mp){
         for(int i=0;i<indices.size();i+=size){
              result.push_back(vector<int>(indices.begin()+i,indices.begin()+i+size));
         }
     }
     return result;
    }
};