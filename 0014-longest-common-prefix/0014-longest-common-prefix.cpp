class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
          int n=strs.size();
   sort(begin(strs), end(strs)) ;

          string str=strs[0];
          string st=strs[n-1];
          string res="";
          for(int i=0;i<str.size();i++){
           if(str[i]==st[i]){
            res+=str[i];
           }else break;
          }
          return res;
      }
};