class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=1;
        int ans=1,x=nums[0];
        while(j<n){
           if((x&nums[j])==0){
             x|=nums[j];
             j++;
             ans=max(ans,j-i);
           }
           else{
            x=x^nums[i];
            i++;
           }
        }
        return ans;
    }
};