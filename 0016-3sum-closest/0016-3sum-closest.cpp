class Solution {
public:
int res=0;
int mini=INT_MAX;
 int twoSum(vector<int>& nums, int k,int x,int target) {
        int i = k, j = nums.size()-1;
        while(i < j) {
            int diff=abs((nums[i]+nums[j]-x));
                if(diff<mini){
                    mini=diff;
                    res=nums[i]+nums[j]+(target-x);
                }
            if(nums[i]+nums[j] > x) j--;
            else if(nums[i] + nums[j] < x) i++;
            else {
               return target;
            }
        }
        return -1;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
         for(int i = 0; i<nums.size()-2; i++) {  //(i<nums.size()-2)Things you must not forget in interviews
            twoSum(nums, i+1, target-nums[i],target);
        }
        return res;
    }
};