class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
       vector<pair<int,string>> vec;
        vector<string> result;

       for(int i=0;i<heights.size();i++){
        vec.push_back({heights[i],names[i]});
       }
       auto lambda=[](auto &a,auto &b){
        return a.first>b.first;
       };

     sort(begin(vec),end(vec),lambda);

    for(auto &idx:vec){
        result.push_back(idx.second);
     }
     return result;
    }
};