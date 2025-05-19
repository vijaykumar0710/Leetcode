class Solution {
public:
bool isValid(string &s1,string &s2){
 if((s2.size()-s1.size())!=1) return false;
 int i=0,j=0;
while(i<s1.size() && j<s2.size()){
    if(s1[i]==s2[j]){
        i++;
    } 
    j++;
  }
  return i==s1.size();
}
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &a,string &b){
                return a.size()<b.size();
        });
        int n=words.size();
        vector<int>t(n,1);
        int maxLen=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(isValid(words[j],words[i])){
                   if(t[j]+1>t[i]){
                    t[i]=t[j]+1;
                    maxLen=max(maxLen,t[i]);
                   }
                }
            }
        }
        return maxLen;
    }
};