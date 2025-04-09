class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int cnt,res=0;
        cnt=nums[0]==0?0:1;
        for(int i=1;i<n;i++){
            if(nums[i]==1 && nums[i]==nums[i-1]){
                cnt++;
            }else{ 
            res=max(res,cnt);
            cnt=nums[i]==0?0:1;
            }
        }
        res=max(res,cnt);
        return res;
    }
};