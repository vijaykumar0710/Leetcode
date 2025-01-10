class Solution {
public:
    long long calculateScore(string s) {
        int n=s.size();
        unordered_map<char,vector<int>>mp;
        long long score=0;
        for(int i=0;i<n;i++){
            if(mp.find('z'-(s[i]-'a'))!=mp.end() && !mp['z'-(s[i]-'a')].empty()){
               int j=mp['z'-(s[i]-'a')].back();
               mp['z'-(s[i]-'a')].pop_back();
               score+=(i-j);
            }
         else mp[s[i]].push_back(i);
        }
        return score;
    }
};