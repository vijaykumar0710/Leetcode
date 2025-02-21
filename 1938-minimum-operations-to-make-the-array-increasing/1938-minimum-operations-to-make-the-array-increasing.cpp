class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int operations=0;
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){ 
            int temp=nums[i-1]-nums[i]+1;
            operations+=temp;
            nums[i]=nums[i]+temp;
            }
        }
        return operations;
    }
};