class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>res;
        unordered_map<string,int>mp;
        string word;

        stringstream ss1(s1);
            while(ss1>>word){
                mp[word]++;
            }
            stringstream ss2(s2);
                while(getline(ss2,word,' ')){
                    mp[word]++;
            }
        for(auto &ch:mp){
          if(ch.second==1){
            res.push_back(ch.first);
          }
        }
        return res;
    }
};