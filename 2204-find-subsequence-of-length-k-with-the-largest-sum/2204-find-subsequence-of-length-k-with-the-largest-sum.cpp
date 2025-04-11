class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>>vec(n);
        for(int i=0;i<nums.size();i++){
            vec[i]={nums[i],i};
        }
        sort(vec.begin(),vec.end());
         vector<pair<int,int>>arr;
        for(int i=n-1;i>=n-k;i--){
           arr.push_back({vec[i].second,vec[i].first});
        }
        sort(arr.begin(),arr.end());
        vector<int>res;
        for(int i=0;i<arr.size();i++){
            res.push_back(arr[i].second);
        }
        return res;
    }
};