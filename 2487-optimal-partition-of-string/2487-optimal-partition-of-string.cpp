class Solution {
public:
    int partitionString(string s) {
      int n=s.size();
      vector<bool>vec(26,false);
      int cnt=0;
      int i=0;
      while(i<n){
         if(vec[s[i]-'a']){
            cnt++;
            vec.assign(26,false);
            vec[s[i]-'a']=true;
         }
        else{
            vec[s[i]-'a']=true;
          }
          i++;
       }
       return cnt+1;
    }
};