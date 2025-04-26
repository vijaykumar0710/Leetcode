class Solution {
public:
    int countAsterisks(string s) {
    int n=s.size();
    vector<int>vec;
    int cnt=0;
    for(int i=0;i<n;i++){
      if(s[i]=='|') vec.push_back(i);
      if(s[i]=='*') cnt++;
       }
       for(int i=0;i<vec.size();i+=2){
        for(int j=vec[i];j<=vec[i+1];j++){
            if(s[j]=='*') cnt--;
         }
       }
       return cnt;
    }
};