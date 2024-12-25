class Solution {
public:
    vector<string>tokens;
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        for(auto &word:words){
        stringstream ss(word);
        string token;
        while(getline(ss,token,separator)){
        if(token.size()!=0)tokens.push_back(token);
           }
        }
          return tokens;
    }
};