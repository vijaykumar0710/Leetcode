class Solution {
public:
    bool checkInclusion(string pat, string txt) {
        int n=txt.size();
     int k=pat.size();
     unordered_map<char,int>mp;
     for(auto &ch:pat){
         mp[ch]++;
     }
     int i=0,j=0,cnt=mp.size();
     while(j<n){
        if(mp.find(txt[j])!=mp.end()){
          mp[txt[j]]--;
             if(mp[txt[j]]==0){
                 cnt--;
             }
        }
         if(j-i+1<k){
             j++;
         }
         else if(j-i+1==k){
              if(cnt==0){
                 return true;
             }
             if(mp.find(txt[i])!=mp.end()){
                if(mp[txt[i]]==0){
                    cnt++;
                }
                mp[txt[i]]++;
             }
             i++;
             j++;
         }
     }
     return false; 
    }
};