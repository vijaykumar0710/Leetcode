class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size(),k=p.size();
        unordered_map<int,int>mp;
        for(auto ch:p){
            mp[ch]++;
        }
        int i=0,j=0,cnt=mp.size();
        vector<int>ans;
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0) cnt--;
            }
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                if(cnt==0) ans.push_back(i);
                if(mp.find(s[i])!=mp.end()){
                    if(mp[s[i]]==0) cnt++;
                    mp[s[i]]++;
                }
                i++,j++;
            }
        }
        return ans;
    }
};