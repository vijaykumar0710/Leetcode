class Solution {
public:
    string finalString(string s) {
      string res="";
      for(auto ch:s){
        if(ch=='i'){
            reverse(res.begin(),res.end());
        }else{
            res+=ch;
        }
      }
      return res;
    }
};