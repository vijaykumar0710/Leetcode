class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                 mp[grid[i][j]]++;
            }
        }
        vector<int>res(2);
        for(int k=1;k<=n*n;k++){
            if(mp.find(k)!=mp.end()){ 
                if(mp[k]==2){ 
               res[0]=k;
                }
            }
             if(mp.find(k)==mp.end()){
                res[1]=k;
             }
        }
        return res;
    }
};