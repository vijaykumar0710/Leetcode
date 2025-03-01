class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        for(int right=0;right<n;right++){
            if(right+1<n && nums[right]==nums[right+1]){
                nums[right]=nums[right]*2;
                nums[right+1]=0;
            }
            if(nums[right]!=0){
                swap(nums[right],nums[left]);
                left++;
            }
        }
        return nums;
    }
};