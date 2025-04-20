class Solution {
public:
void solve(vector<int>& nums,int idx,vector<vector<int>>&res,vector<int>&vec){
if(idx==nums.size()){
    res.push_back(vec);
    return;
   }
   solve(nums,idx+1,res,vec);
    vec.push_back(nums[idx]);
    solve(nums,idx+1,res,vec);
    vec.pop_back();
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>vec;
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        solve(nums,0,res,vec);
     //   sort(res.begin(),res.end());
        return res;
    }
};