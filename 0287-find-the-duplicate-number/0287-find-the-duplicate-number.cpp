class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
            if(nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
            else{
                i++;
            }
        }
        int duplicate=0;
        for(int i=0;i<n;i++){
            if(i!=nums[i]-1)
                duplicate=nums[i];
        }
        return duplicate;
    }
};