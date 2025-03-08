class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int>mp;
        for(auto ch:s){
            mp[ch]++;
        }
        int check=mp[s[0]];
        for(auto [_,freq]:mp){
            if(check!=freq)
                return false;
        }
        return true;
    }
};