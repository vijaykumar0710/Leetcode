class Solution {
public:
 long long t[100001];
 long long solve(vector<pair<long long,long long>>&arr,int n,int idx, long long &ans){
    if(idx>=n) return 0;
    if(t[idx]!=-1) return t[idx];
    int j;
    for(int i=idx+1;i<n;i++){
        if(arr[i].first-arr[idx].first>2){
          j=i;
          break;
        }
    }
   ans=max((arr[idx].first*arr[idx].second)+solve(arr,n,j,ans),solve(arr,n,idx+1,ans));
   t[idx]=ans;
    return t[idx]=ans;
}
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int,int>mp;
        for(auto &num:power){
            mp[num]++;
        }
        vector<pair<long long,long long>>arr;
        for(auto [ele,freq]:mp){
            arr.push_back({ele,freq});
        }
        sort(arr.begin(),arr.end());
        int n=arr.size();
        long long ans=0;
        memset(t,-1,sizeof(t));
       return solve(arr,n,0,ans);
    }
};