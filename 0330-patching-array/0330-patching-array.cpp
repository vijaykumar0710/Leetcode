class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long maxReach=0;
        int patch=0;
        int i=0;
        while(maxReach<n){
            if(i<nums.size() && maxReach+1>=nums[i]){
                maxReach+=nums[i];
                i++;
            }else{
                patch++;
                maxReach+=(maxReach+1);
            }
        }
        return patch;
    }
};