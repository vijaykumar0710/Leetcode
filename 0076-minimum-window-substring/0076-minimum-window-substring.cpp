class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.length();
        int n=t.length();
        unordered_map<char,int>mp;
        for(char &ch:t){
            mp[ch]++;
        }

       int requiredCount=n;
       int i=0,j=0;
       int minWindowSize=INT_MAX;
       int start_i=0;

  while(j<m){
    char ch=s[j];
    if(mp[ch]>0) 
      requiredCount--;
    mp[ch]--;
    while(requiredCount==0){
        int currWIndowSize=j-i+1;
       if(minWindowSize>currWIndowSize){
        minWindowSize=currWIndowSize;
        start_i=i;
           }
           mp[s[i]]++;
           if(mp[s[i]]>0){
            requiredCount++;
           }
           i++;
         }
         j++;
      }
      return minWindowSize==INT_MAX ? "" : s.substr(start_i,minWindowSize);
    }
};