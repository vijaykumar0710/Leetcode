class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>mp;
        for(auto &x:s){
            mp[x]++;
        }
        int cnt=0;
        for(auto &y:t){
          if(mp.find(y)==mp.end()){
            cnt++;
          }else{
            mp[y]--;
            if(mp[y]==0)
              mp.erase(y);
          }
        }
        return cnt;
    }
};