class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        vector<int>t(n,1);
        int maxLen=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
              if(pairs[i][0]>pairs[j][1]){
                if(t[j]+1>t[i]){
                    t[i]=t[j]+1;
                    maxLen=max(maxLen,t[i]);
                }
              }
            }
        }
        return maxLen;
    }
};