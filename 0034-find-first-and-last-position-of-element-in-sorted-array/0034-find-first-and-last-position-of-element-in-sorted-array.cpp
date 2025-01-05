class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0,j=n-1;
         vector<int>res(2,-1);
        while(i<n){
            if(nums[i]==target){
                res[0]=i;
                break;
            }
            i++;
        }
         while(j>=0){
            if(nums[j]==target){
                res[1]=j;
                break;
            }
            j--;
        }
        return res;
    }
};