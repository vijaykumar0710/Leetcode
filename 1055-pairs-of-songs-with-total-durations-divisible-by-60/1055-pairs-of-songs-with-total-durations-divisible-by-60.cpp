class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int>vec;
        for(auto &num:time){
            vec.push_back(num%60);
        }
        int n=vec.size();
        unordered_map<int,int>mp;
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            if(vec[i]!=0 && mp.find(60-vec[i])!=mp.end()){
             cnt+=mp[60-vec[i]];
            }
            if(vec[i]==0 && mp.find(vec[i])!=mp.end()){
             cnt+=mp[vec[i]];
            }
            mp[vec[i]]++;
        }
        return cnt;
    }
};