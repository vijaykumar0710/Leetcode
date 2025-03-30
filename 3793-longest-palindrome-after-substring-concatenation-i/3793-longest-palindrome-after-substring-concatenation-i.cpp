class Solution {
public:
bool checkPalindrome(string &s){
    int n=s.size();
    int i=0,j=n-1;
    while(i<=j){
        if(s[i]!=s[j])
           return false;
        i++;
        j--;
    }
    return true;
}
    int longestPalindrome(string s, string t) {
        int m=s.size();
        int n=t.size();
        int ans=1;
        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                string strs=s.substr(i,j-i+1);
                int size1=strs.size();
                if(checkPalindrome(strs)){
                    ans=max(ans,size1);
                       }
                    for(int k=0;k<n;k++){
                       for(int l=k;l<n;l++){
                        string strt=t.substr(k,l-k+1);
                        int size2=strt.size();
                         if(checkPalindrome(strt)){
                            ans=max(ans,size2);
                       }
                       string str=strs+strt;
                       int size=str.size();
                        if(checkPalindrome(str)){
                           ans=max(ans,size);
                         }
                    }
               }
           }
        }
        //  if(checkPalindrome(s)){
        //   ans=max(ans,m);
        //  }
        //  if(checkPalindrome(t)){
        //   ans=max(ans,n);
        //  }
         return ans;
    }
};