class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mini=nums[0],min_idx=0;
        int maxi=nums[0],max_idx=0;
        for(int i=1;i<n;i++){
            if(nums[i]<mini){
                mini=nums[i];
                min_idx=i;
            }
            if(nums[i]>maxi){
                maxi=nums[i];
                max_idx=i;
            }
        }
         if(max_idx==n/2 || min_idx==n/2){
            if(n%2==0 && (max_idx>n/2 || min_idx>n/2)) return n/2;
            else return (n/2)+1;
        }
        else{
            int t1=min(min_idx,max_idx)+1+n-max(min_idx,max_idx);
            int t2=max(min_idx,max_idx)+1;
            int t3=n-min(min_idx,max_idx);
            return min({t1,t2,t3});
        }
        return -1;
    }
};