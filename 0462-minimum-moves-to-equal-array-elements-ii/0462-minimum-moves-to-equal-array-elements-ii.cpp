class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int median=nums[n/2];
        long long cnt=0;
         for(auto num:nums){
            cnt+=abs(num-median);
        }
        return cnt;
    }
};