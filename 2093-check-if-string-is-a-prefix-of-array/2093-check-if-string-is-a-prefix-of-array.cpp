class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int j=0;
        for(int i=0;i<words.size()&&j<s.size();i++){
          int x=words[i].size();
          if(s.substr(j,x)!=words[i])
             return false;
         j+=x;
        }
        if(j<s.size()) return false;
        return true;
    } 
};