class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int cnt=0;
        for(int i=0;i<n-1;i++){
            int len=words[i].size();
            for(int j=i+1;j<n;j++){
                int size=words[j].size();
               if(words[j].substr(0,len)==words[i] && words[j].substr(size-len,len)==words[i]){
                cnt++;
               }
            }
        }
        return cnt;
    }
};