class Solution {
public:
int t[10][2][10];
int solve(string &s,int idx,int tight,int cnt){
  if(idx==s.size()) return cnt;
  if(t[idx][tight][cnt]!=-1) return t[idx][tight][cnt];
  long long limit=(tight==1?s[idx]-'0':9);
  long long ans=0;
  for(int i=0;i<=limit;i++){
    int updateCnt=cnt+(i==1?1:0);
    ans+=solve(s,idx+1,tight&(i==s[idx]-'0'),updateCnt);
  }
  return t[idx][tight][cnt]=ans;
}
    int countDigitOne(int n) {
        string r=to_string(n);
        memset(t,-1,sizeof(t));
        return solve(r,0,1,0);
    }
};