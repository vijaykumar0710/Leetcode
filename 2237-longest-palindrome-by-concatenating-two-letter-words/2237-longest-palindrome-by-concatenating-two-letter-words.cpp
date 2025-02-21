class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        for(auto &word:words){
            mp[word]++;
        }
        int cnt=0;
        bool centreUsed=false;
        for(auto &word:words){
            string revWord=word;
            reverse(revWord.begin(),revWord.end());
           if(word!=revWord){
              if(mp[word]>0 && mp[revWord]>0){
                mp[word]--;
                mp[revWord]--;
                cnt+=4;
              }
           }else{
               if(mp[word]>=2){
                mp[word]-=2;
                cnt+=4;
               }else if(mp[word]==1 && centreUsed==false){
                mp[word]--;
                cnt+=2;
                centreUsed=true;
               }
           }
        }
        return cnt;
    }
};