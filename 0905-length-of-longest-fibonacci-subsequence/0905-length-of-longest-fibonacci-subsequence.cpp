class Solution {
public:
int t[1001][1001];
int solve(int j,int k,vector<int>&arr,unordered_map<int,int>&mp){
   // if(t[j][k]!=-1) return t[j][k];
    int target=arr[k]-arr[j];
    if(mp.count(target) && mp[target]<j){
        int i=mp[target];
        return solve(i,j,arr,mp)+1;
    }
    return 2;
}
    int lenLongestFibSubseq(vector<int>& arr) {
       int n=arr.size();
       unordered_map<int,int>mp;
       for(int i=0;i<n;i++){
        mp[arr[i]]=i;
       }
      memset(t,-1,sizeof(t));
       int max_len=0;
       for(int j=1;j<n;j++){
        for(int k=j+1;k<n;k++){
            int len=solve(j,k,arr,mp);
            if(len>=3){
              max_len=max(max_len,len);
            }
          }
       } 
       return max_len>=3?max_len:0;
    }
};