class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        unordered_map<char,int>mp;
        if(k==n)return true;
        if(k>n)return false;
        for(auto &ch:s){
            mp[ch]++;
        }
        int cnt=0;
        for(auto &[ch,freq]:mp){
            if(freq%2!=0){
                cnt++;
            }
        }
        return cnt>k?false:true;
    }
};