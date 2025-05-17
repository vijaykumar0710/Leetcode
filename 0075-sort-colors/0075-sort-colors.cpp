class Solution {
public:
    void sortColors(vector<int>& nums) {
      int zero=0,one=0,two=0;
      for(auto &num:nums){
        if(num==0) zero++;
        else if(num==1) one++;
        else two++;
      }
      for(int i=0;i<nums.size();i++){
         while(zero--){
            nums[i]=0;
            i++;
         }
         while(one--){
            nums[i]=1;
            i++;
         }
         while(two--){
            nums[i]=2;
            i++;
         }
      }
    }
};