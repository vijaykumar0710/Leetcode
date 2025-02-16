class Solution {
public:
int n;
int minSum=INT_MAX;
vector<int>result;
void solve(vector<int>& nums,vector<bool>&visited,vector<int>&perm,int sum){
  if(sum>minSum) return; //pruning:- hame toh minimum chahiye agar sum minSum se jyada ho gya to return ho jao koi fayeda nahi hain
    if(perm.size()==n){
        sum+=abs(perm.back()-nums[perm[0]]);
        if(sum<minSum){
            minSum=sum;
            result=perm;
        }
    }
   for(int i=0;i<n;i++){
    if(!visited[i]){
        visited[i]=true;
        perm.push_back(i);
        solve(nums,visited,perm,sum+abs(perm[perm.size()-2]-nums[perm[perm.size()-1]]));
        perm.pop_back();
        visited[i]=false;
    }
   }
}
    vector<int> findPermutation(vector<int>& nums) {
    n=nums.size();
    vector<bool>visited(n,false);
    vector<int>perm={0}; //lexicographically smallest will start from 0
    visited[0]=true;
    solve(nums,visited,perm,0);
    return result;
    }
};