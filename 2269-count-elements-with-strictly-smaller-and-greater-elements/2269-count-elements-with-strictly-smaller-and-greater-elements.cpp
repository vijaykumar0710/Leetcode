class Solution {
public:
    int countElements(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int cnt=0;
        for(int i=1;i<n-1;i++){
            if(nums[i]>nums[0] && nums[i]<nums[n-1]){
                cnt++;
            }
        }
      return cnt;
    }
};