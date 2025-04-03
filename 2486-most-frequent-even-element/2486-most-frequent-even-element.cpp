class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto num:nums){
            if(num%2==0){ 
            mp[num]++;
            }
        }
        if(mp.size()==0)
           return -1;
        vector<pair<int,int>>vec;
        for(auto [num,freq]:mp){
            vec.push_back({freq,num});
        }
        auto lambda=[](pair<int,int>&a,pair<int,int>&b){
            if(a.first==b.first)
               return a.second<b.second;
            return a.first>b.first;
        };
        sort(vec.begin(),vec.end(),lambda);
       return vec[0].second;
    }
};