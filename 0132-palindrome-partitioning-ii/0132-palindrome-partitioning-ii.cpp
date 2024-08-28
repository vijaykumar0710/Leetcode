class Solution {
public:
bool isPalindrome(int i,int j,string &s){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
} 
int f(int i,int n,string &s,vector<int>&t){
  if(i==n) return 0;
  int min_partition=INT_MAX;
  if(t[i]!=-1) return t[i];
  for(int j=i;j<n;j++){
    if(isPalindrome(i,j,s)){
     int partition=1+f(j+1,n,s,t);
     min_partition=min(min_partition,partition);
    }
  }
  return t[i]=min_partition;
}
    int minCut(string s) {
        int n=s.length();
       vector<int>t(n,-1);
        return f(0,n,s,t)-1;
    }
};