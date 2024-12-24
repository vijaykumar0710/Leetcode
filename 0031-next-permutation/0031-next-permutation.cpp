class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int idx=-1;
      for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            idx=i;
            break;
        }
      }  
      if(idx==-1){
        reverse(nums.begin(),nums.end());
        return;
      }
     reverse(nums.begin()+(idx+1),nums.begin()+n);
     int just_max=-1;
     for(int i=idx+1;i<n;i++){
        if(nums[i]>nums[idx]){
            just_max=i;
            break;
        }
     }
     int temp=nums[idx];
     nums[idx]=nums[just_max];
     nums[just_max]=temp;
     return;
    }
};