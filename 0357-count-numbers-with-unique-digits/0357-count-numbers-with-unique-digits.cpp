class Solution {
public:
void solve(int n,int &cnt,string &s,vector<bool>&used){
  if(s.size()==n){
    cnt++;
    return;
  }
  for(int i=0;i<=9;i++){ 
    if(s.empty() && i==0 && n>1) continue;
    if(used[i]) continue;
    used[i]=true;
    s.push_back(i+'0');
    solve(n,cnt,s,used);
    used[i]=false;
    s.pop_back();
  }
}
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        string s="";
        int cnt=0;
       for (int len = 1; len <= n; len++) {  // Loop over lengths from 1 to n
            string s = "";
            vector<bool> used(10, false);
            solve(len, cnt, s, used);
        }
        return cnt;
    }
};