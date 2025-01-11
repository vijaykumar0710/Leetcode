class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeros=0;
        int pro=1;
        for(auto &num:nums){
            if(num==0){
                zeros++;
            }
            if(num==0){
                pro*=1;
            }
           else pro*=num;
        }
        if(zeros>=2){
            for(int i=0;i<nums.size();i++){
                nums[i]=0;
            }
        }
        else if(zeros==1){
            for(int i=0;i<nums.size();i++){
                  if(nums[i]==0)nums[i]=pro;
                  else nums[i]=0;
            }
        }
        else{ 
      for(int i=0;i<nums.size();i++){
        nums[i]=pro/nums[i];
           }
        }
      return nums;
    }
};