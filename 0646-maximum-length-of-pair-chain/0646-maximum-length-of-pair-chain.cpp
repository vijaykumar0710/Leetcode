class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int>temp(n,1);
       for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(pairs[i][0]>pairs[j][1]){
                temp[i]=max(temp[i],temp[j]+1);
            }
         }
       }
       return *max_element(temp.begin(),temp.end());
    }
};