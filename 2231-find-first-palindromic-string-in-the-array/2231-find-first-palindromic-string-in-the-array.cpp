class Solution {
public:
bool isPalindrome(string &a){
    int n=a.size();
    int i=0,j=n-1;
    while(i<=j){
        if(a[i]!=a[j]) return false;
        i++,j--;
    }
    return true;
}
    string firstPalindrome(vector<string>& words) {
        string res="";
        for(auto &word:words){
            if(isPalindrome(word)){
                res=word;
                return res;
            }
        }
        return res;
    }
};