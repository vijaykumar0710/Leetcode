class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        int sum=0,mini=n;
        while(j<n){
            sum+=nums[j];
         while(sum>=target){
           mini=min(mini,j-i+1);
           sum-=nums[i];
           i++;
           }
           j++;
        }
        if(mini==n) return 0;
        return mini;
    }
};