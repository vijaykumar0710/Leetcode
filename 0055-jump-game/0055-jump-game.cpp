class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int max_reachable=0;
        for(int i=0;i<n;i++){
            if(i>max_reachable) return false;
            max_reachable=max(max_reachable,nums[i]+i);
        }
        return true;
    }
};