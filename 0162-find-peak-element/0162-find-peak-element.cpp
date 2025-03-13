class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        if(n==2){
         if( nums[0]>nums[1]){
                return 0;
            }
           else if( nums[1]>nums[0]){
                return 1;
            }  
        }
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                return i;
                break;
            }
        }
        return -1;
    }
};