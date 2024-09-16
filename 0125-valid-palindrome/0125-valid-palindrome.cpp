class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        if(n==0)return true;
        string pali="";
        for(auto &ch:s){
           if(isalnum(ch)){
              pali+=tolower(ch);
           }
        }
        int i=0,j=pali.size()-1;
        while(i<j){
            if(pali[i]!=pali[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};