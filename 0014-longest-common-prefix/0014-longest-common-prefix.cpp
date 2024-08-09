class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
          
   sort(begin(strs), end(strs)) ;


          string str=strs[0];
          for(int i=1;i<strs.size();i++){
            int j=0;
           while (j < str.size() && str[j] == strs[i][j]) {
                j++;
            }
            str = str.substr(0, j);
          }
          if(str.empty()) return "";
          return str;
      }
};