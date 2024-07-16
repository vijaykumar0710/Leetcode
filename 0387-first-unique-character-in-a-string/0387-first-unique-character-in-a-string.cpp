class Solution {
public:
    int firstUniqChar(string s) {
       unordered_map<char,int>mp;
       for(auto &ch:s){
        mp[ch]++;
       } 
       
       for(int j=0;j<s.length();j++){
        if(mp[s[j]]==1){
            return j;
          }
       } 
       return -1;
    }
};