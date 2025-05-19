class Solution {
public:
bool isValid(string s1, string& s2) {
        int cnt = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) cnt++;
            if(cnt>1) return false;
        }
        return cnt == 1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        int longestSub=1,LISIdx=0;
        vector<int>t(n,1),prevIdx(n,-1);
     for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(groups[i]!=groups[j] && words[i].size()==words[j].size() && isValid(words[i],words[j])){
               if(t[j]+1>t[i]){
                t[i]=t[j]+1;
                prevIdx[i]=j;
                if(t[i]>longestSub){
                    longestSub=t[i];
                     LISIdx=i;
                  }
               }
            }
        }
      }
      vector<string>res;
      while(LISIdx!=-1){
        res.push_back(words[LISIdx]);
        LISIdx=prevIdx[LISIdx];
      }
      reverse(res.begin(),res.end());
      return res;
    }
};