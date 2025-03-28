class Solution {
public:
int t[1002][1002];
int knapsack(vector<pair<int,int>>&vec,int idx,int prev_idx,int n){
if(idx==n){
    return 0;
}
if(t[idx][prev_idx+1]!=-1) return t[idx][prev_idx+1];
int skip=knapsack(vec,idx+1,prev_idx,n);
int take=0;
  if(prev_idx==-1 || vec[idx].second>=vec[prev_idx].second){
         take=vec[idx].second+knapsack(vec,idx+1,idx,n);
     }
  return t[idx][prev_idx+1]=max(take,skip);
}
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
       int n=ages.size();
       vector<pair<int,int>>vec;
       for(int i=0;i<n;i++){
        vec.push_back({ages[i],scores[i]});
       }
       sort(vec.begin(),vec.end());
       memset(t,-1,sizeof(t));
       return knapsack(vec,0,-1,n);
    }
};