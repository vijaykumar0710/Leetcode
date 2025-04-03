class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto ch:s){
            mp[ch]++;
        }
        vector<pair<int,char>>vec;
        for(auto &[ch,num]:mp){
            vec.push_back({num,ch});
        }
        auto lambda=[](pair<int,char>&a,pair<int,char>&b){
            return a.first>b.first;
        };
        sort(vec.begin(),vec.end(),lambda);
        string res="";
        for(auto [num,ch]:vec){
            int n=num;
           while(n){
            res+=ch;
            n--;
           }
        }
        return res;
    }
};