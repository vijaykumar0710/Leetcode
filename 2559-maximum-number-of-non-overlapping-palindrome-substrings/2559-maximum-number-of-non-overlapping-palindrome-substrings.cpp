class Solution {
    public:
    bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int n=s.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int len= j-i+1;
                if(len>k+1){  //greedy
                    break;
                }
                if((len>=k) && isPalindrome(s, i, j)){
                    ans++; 
                    i=j;
                    break;
                }
            }
        }
        return ans;
    }
};