class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n=nums.size();  
        for(int i=0;i<n-1;i++){
            if(i-1>=0 && nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                return i;
                break;
            }
        }
        return -1; 
    }
};