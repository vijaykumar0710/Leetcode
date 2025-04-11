class Solution {
public:
void twoSum(vector<int>&nums,int k,long long x,vector<vector<int>>&res,int first,int second){
    int i=k,j=nums.size()-1;
    while(i<j){
         long long sum=1ll*nums[i]+nums[j];
        if(sum<x) i++;
        else if(sum>x) j--;
        else{
            res.push_back({nums[i],nums[j],nums[first],nums[second]});
            while(i<j && nums[i]==nums[i+1]) i++;
            while(i<j && nums[j]==nums[j-1]) j--;
            i++;
            j--;
        }
    }
}
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        if(n<4) return res;
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                 long long x=1ll*target-(nums[i]+nums[j]);
               twoSum(nums,j+1,x,res,i,j);
            }
        }
        return res;
    }
};