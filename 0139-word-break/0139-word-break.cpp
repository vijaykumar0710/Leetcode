class Solution {
public:
bool solve(string &s,unordered_set<string>&st,unordered_map<string,bool>&memo){
    if(s.empty()){
        return true;
    }
    if(memo.find(s)!=memo.end()) return memo[s];
    for(int j=1;j<=20;j++){
        string str=s.substr(0,j);
        if(st.find(str)!=st.end()){
            string rem=s.substr(j);
        if(solve(rem,st,memo)){
            return memo[s]=true;
          }
        }
    }
    return memo[s]=false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
    int n=s.length();

      unordered_set<string>st;
      unordered_map<string,bool>memo;
      for(auto &word:wordDict){
        st.insert(word);
      }
      return solve(s,st,memo);
    }
};