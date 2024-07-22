class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> mp;
        vector<string> result;

       for(int i=0;i<heights.size();i++){
        mp[heights[i]]=names[i];
       }
     
    for(auto &idx:mp){
        result.push_back(idx.second);
     }
     reverse(begin(result),end(result));
     return result;
    }
};