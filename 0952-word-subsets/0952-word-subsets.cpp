class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int>mp2;
        for(auto &word:words2){
           unordered_map<char,int>freq;
           for(auto &ch:word){
            freq[ch]++;
           }
           for(auto &[ch,count]:freq){
            mp2[ch]=max(mp2[ch],count);
           }
        }
        vector<string>result;
      for(auto &word:words1){
        unordered_map<char,int>mp1;
        for(auto &ch:word){
            mp1[ch]++;
         }
         bool flag=true;
         for(auto &[ch,count]:mp2){
            if(mp1[ch]<count){
                flag=false;
                break;
            }
         }
         if(flag==true){
            result.push_back(word);
           }
      }
      return result;
    }
};