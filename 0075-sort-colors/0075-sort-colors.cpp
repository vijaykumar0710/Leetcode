class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=0,k=nums.size()-1;
        while(j<=k){
            if(nums[j]==1) j++;
            else if(nums[j]==2){
                swap(nums[j],nums[k]);
                k--;
            }else{
                swap(nums[i],nums[j]);
                i++,j++;
            }
        }
    }
};