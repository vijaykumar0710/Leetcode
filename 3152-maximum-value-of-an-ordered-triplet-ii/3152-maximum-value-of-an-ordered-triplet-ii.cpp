class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>leftmaxi(n);
        vector<int>rightMaxk(n); 
    
        for(int i=1;i<n;i++){
            leftmaxi[i]=max(nums[i-1],leftmaxi[i-1]);
        }  
        for(int i=n-2;i>=0;i--){
            rightMaxk[i]=max(nums[i+1],rightMaxk[i+1]);
        }  

        long long ans=0;
        for(int i=1;i<n;i++){
           ans=max(ans,(long long)((long long)(leftmaxi[i]-nums[i])*rightMaxk[i]));
        }
        return ans;
    }
};