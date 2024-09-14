class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int maxi=*max_element(begin(nums),end(nums));
        int res=0;
        int currLen=0;
        for(int i=0;i<n;i++){
        if(nums[i]==maxi){
            currLen++;
        }else{
            res=max(res,currLen);
            currLen=0;
        }
        }
        res=max(res,currLen); 
        return res;
    }
};