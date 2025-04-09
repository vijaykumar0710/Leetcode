class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size();
        vector<int>vec;
        int i=0,cnt=0;;
        while(i<n){
          if(s[i]=='0'){
            while(s[i]=='0'){ 
              cnt++;
              i++;
          }
          vec.push_back(cnt);
          cnt=0;
          }
        else{
            while(s[i]=='1'){ 
              cnt++;
              i++;
            }
          vec.push_back(cnt);
          cnt=0;
        }
     }
     int res=0;
     int size=vec.size();
     for(int i=1;i<size;i++){
        res+=min(vec[i],vec[i-1]);
     }
     return res;
    }
};