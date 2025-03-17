class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int mini=INT_MAX,ans=INT_MAX;
        sort(begin(nums),end(nums));
        for(auto num:nums){
         if(abs(num)<=mini){
            ans=num;
            mini=abs(num);
         }
        }
        return ans;
    }
};