class Solution {
public:
void backtrack(string &s,unordered_set<string>&st,int idx,vector<string>&res,vector<string>&word){
if(idx==s.size()){
    string temp=word[0];
  for(int k=1;k<word.size();k++){
     temp=temp+" "+word[k];
  }
  res.push_back(temp);
  return;
   }
   for(int i=idx;i<s.size();i++){
    string sub=s.substr(idx,i-idx+1);
    if(st.find(sub)!=st.end()){
        word.push_back(sub);
        backtrack(s,st,i+1,res,word);
        word.pop_back();
     }
   }
}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>res;
        vector<string>word;
        unordered_set<string>st;
        for(auto &ch:wordDict){
            st.insert(ch);
        }
        backtrack(s,st,0,res,word);
        return res;
    } 
};