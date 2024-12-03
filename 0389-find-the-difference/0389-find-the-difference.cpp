class Solution {
public:
    char findTheDifference(string s, string t) {
        string newS=s+t;
        char rem=0;
        for(auto &ch:newS){
             rem=rem^ch;
        }
        return rem;
    }
};