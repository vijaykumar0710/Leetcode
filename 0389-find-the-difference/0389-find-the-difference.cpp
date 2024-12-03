class Solution {
public:
    char findTheDifference(string s, string t) {
        char rem=0;
        for(auto &ch:s){
             rem^=ch;
        }
        for(auto &ch:t){
             rem^=ch;
        }
        return rem;
    }
};