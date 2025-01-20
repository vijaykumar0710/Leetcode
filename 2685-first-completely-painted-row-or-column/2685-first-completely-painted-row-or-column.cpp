class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        unordered_map<int,pair<int,int>>mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[mat[i][j]]={i,j};
            }
        }
        vector<int>row_mp(m,0);
        vector<int>col_mp(n,0);
        for(int i=0;i<arr.size();i++){
           auto[ row,col]=mp[arr[i]];
           row_mp[row]++;
           col_mp[col]++;
           if(row_mp[row]==n || col_mp[col]==m){
            return i;
           }
        }
        return -1;
    }
};