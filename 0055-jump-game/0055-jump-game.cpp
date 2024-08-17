class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int max_go=0;
        for(int i=0;i<n;i++){
          if(i>max_go) return false;
          max_go=max(max_go,nums[i]+i);
        }
        return true;
    }
};