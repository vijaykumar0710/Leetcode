class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
         int n=nums.size();
        int cnt=1,res=0;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                cnt++;
            }else{
              res=max(res,cnt);
              cnt=1;
            }
        }
        res=max(res,cnt);// compare last group
        return res;  
    }
};