class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(auto &ch:ransomNote){
            mp1[ch]++;
        }
         for(auto &ch:magazine){
            mp2[ch]++;
        }
       for(auto &ch:mp1){
       if(mp2[ch.first]<ch.second){
        return false;
          }
       }
       return true;
    }
};