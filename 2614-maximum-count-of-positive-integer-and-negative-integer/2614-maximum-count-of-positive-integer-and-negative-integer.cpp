class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int i=0;
        while(i<n && nums[i]<1){
            if(nums[i]!=0){
                cnt++;
            }
            i++;
        }
         return max(cnt,(n-i));
    }
};