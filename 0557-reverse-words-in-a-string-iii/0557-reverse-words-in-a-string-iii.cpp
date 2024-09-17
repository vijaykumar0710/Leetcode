class Solution {
public:
    string reverseWords(string s) {
        string res;
        stringstream ss(s);
        string word;
        while(getline(ss,word,' ')){
            reverse(word.begin(),word.end());
            res+=word+' ';
        }
         res.erase(res.find_last_not_of(" \t\n\r") + 1);
        return res;
    }
};