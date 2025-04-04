class Solution {
public:
bool isPalindrome(string &s,int i,int j){
    int l=i,r=j;
    while(l<=r){
        if(s[l]!=s[r]){
            return false;
        }
        l++,r--;
    }
    return true;
}
    string longestPalindrome(string s) {
       int n=s.size();
       int maxi=0;
        int l,r;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j)){ 
                    if(maxi<(j-i+1)){ 
                        maxi=j-i+1;
                      l=i,r=j;
                    }
                }
            }
        }
        return s.substr(l,(r-l+1));
    }
};