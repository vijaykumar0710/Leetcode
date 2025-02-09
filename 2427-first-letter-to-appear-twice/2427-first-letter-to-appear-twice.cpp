class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int>freq(26,0);
        for(auto &ch:s){
            if(freq[ch-'a']==1) return ch;
            freq[ch-'a']++;
        }
        return 0;
    }
};