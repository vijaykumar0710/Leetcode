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
    int minCut(string s) {
        int n=s.size();
       vector<int>t(n+1,0);
       t[n]=0;
      for(int i=n-1;i>=0;i--){
      
      int min_partition=INT_MAX; 

      for(int j=i;j<n;j++){
      if(isPalindrome(i,j,s)){
      int partition=1+t[j+1];
      min_partition=min(min_partition,partition);
      }
    }
     t[i]=min_partition;
       }
        return t[0]-1;
    }
};