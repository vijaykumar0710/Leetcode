class Solution {
public:
    int totalFruit(vector<int>& s) {
         unordered_map<int,int>mp;
      int n=s.size();
      int ans=1;
      int i=0,j=0;
      while(j<n){
          mp[s[j]]++;
           if(mp.size()<=2){
              ans=max(ans,(j-i+1));
              j++;
          }
          else if(mp.size()>2){
              while(mp.size()>2){
              if(mp.find(s[i])!=mp.end()){
                  mp[s[i]]--;
                  if(mp[s[i]]==0){
                      mp.erase(s[i]);
                  }
              }
              i++;
              }
              j++;
          }
       }
       return ans;
    }
};