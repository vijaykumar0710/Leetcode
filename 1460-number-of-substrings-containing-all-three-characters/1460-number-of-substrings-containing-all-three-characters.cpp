class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        int cnt=0;
        int i=0,j=0;
        while(j<n){
            char ch=s[j];
            mp[ch]++;
            while(mp.size()==3){
                cnt+=(n-j);
                char ch=s[i];
                i++;
                mp[ch]--;
                 if(mp[ch]==0){
                    mp.erase(ch);
                }
            }
            j++;
        }
        return cnt;
    }
};