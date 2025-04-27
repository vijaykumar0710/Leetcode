class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<=n-3;i++){
            int x=nums[i];
            int y=nums[i+1];
            int z=nums[i+2];
            if(2*(x+z)==y)
               cnt++;
        }
        return cnt;
    }
};