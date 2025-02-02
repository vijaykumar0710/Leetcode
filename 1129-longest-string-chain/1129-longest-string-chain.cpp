class Solution {
public:
  bool checkPredecessor(string &s1,string &s2){
      int i = 0, j = 0;
      while (i < s1.size() && j < s2.size()){
        if (s1[i] == s2[j]) {
            i++; 
        }
        j++; 
    }
    return i == s1.size();
  }
    int longestStrChain(vector<string>& words){
        int n=words.size();
        sort(words.begin(),words.end(),[](string &a,string &b){
            return a.length()<b.length();
        });
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if((words[i].length()-words[j].length())==1 && checkPredecessor(words[j],words[i])){
                   dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};