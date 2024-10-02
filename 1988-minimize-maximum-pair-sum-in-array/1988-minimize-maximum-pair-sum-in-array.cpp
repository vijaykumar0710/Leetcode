class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int result=0;
        int i=0,j=n-1;
        while(i<=j){
            int sum=nums[i]+nums[j];
            i++;
            j--;
            result=max(sum,result);
        }
        return result;
    }
};