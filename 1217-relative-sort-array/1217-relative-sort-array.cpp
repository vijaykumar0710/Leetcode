class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mp;
        vector<int>res;
        for(int i=0;i<arr1.size();i++){
            mp[arr1[i]]++;
        }
        for(int i=0;i<arr2.size();i++){
            if(mp.find(arr2[i])!=mp.end()){
                int x=mp[arr2[i]];
                mp.erase(arr2[i]);
                for(int j=0;j<x;j++){
                res.push_back(arr2[i]);
               }
            }
        }
        vector<int>vec;
       for(int i=0;i<arr1.size();i++){
            if(mp.find(arr1[i])!=mp.end()){
                int x=mp[arr1[i]];
                mp.erase(arr1[i]);
               for(int j=0;j<x;j++){
                vec.push_back(arr1[i]);
               }
            }
        }
        sort(begin(vec),end(vec));
        for(auto &num:vec){
            res.push_back(num);
        }
        return res;
    }
};