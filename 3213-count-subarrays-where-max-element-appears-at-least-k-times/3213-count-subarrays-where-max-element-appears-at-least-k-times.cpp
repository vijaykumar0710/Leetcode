class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        long long cnt=0,res=0;
        long long i=0,j=0;
        while(j<n){
            if(nums[j]==maxi) cnt++;
            if(cnt>=k){
                while(cnt>=k){
                    res+=(n-j);
                    if(i<n && nums[i]==maxi){ 
                        cnt--;
                    } 
                    i++;
                }
            }
            j++;
        }
        return res;
    }
};