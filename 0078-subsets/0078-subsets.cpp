class Solution {
public:
void solve(vector<int>& nums,int idx,vector<vector<int>>&subset,vector<int>&vec){
if(idx==nums.size()){
    subset.push_back(vec);
    return;
}
   solve(nums,idx+1,subset,vec);

   vec.push_back(nums[idx]);
   solve(nums,idx+1,subset,vec);
   vec.pop_back();
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>subset;
        vector<int>vec;
        solve(nums,0,subset,vec);
        return subset;
    }
};