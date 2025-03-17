class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        unordered_map<int,int>mp;
        for(auto ch:t){
            mp[ch]++;
        }
        int i=0,j=0;
        int cnt=mp.size();
        int size=n+1;
        int start=-1;
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
              mp[s[j]]--;
              if(mp[s[j]]==0) cnt--;
           }
           j++;
            while(cnt==0){
              if(j-i<size){
                start=i;
                size=j-i;
              }
              if(mp.find(s[i])!=mp.end()){
                mp[s[i]]++;
                if(mp[s[i]]>0) cnt++;
             }
             i++;
           }
        }
        if(start==-1) return "";
        return s.substr(start,size);
    }
};