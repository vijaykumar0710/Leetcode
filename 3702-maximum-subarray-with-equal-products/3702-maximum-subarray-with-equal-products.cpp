class Solution {
public:
long long MOD=1e9+7;
    int maxLength(vector<int>& nums) {
       int n=nums.size();
       int max_len=0;
       for(int i=0;i<n;i++){
        int currGcd=nums[i];
        int currlcm=nums[i];
        long long currPro=nums[i];
      for(int j=i+1;j<n;j++){
        currGcd=gcd(currGcd,nums[j]);
        currlcm=lcm(currlcm,nums[j]);
         currPro=(currPro*nums[j])%MOD;
          if(currPro==(currGcd*currlcm)%MOD)
          max_len=max(max_len,j-i+1);
         }
       } 
       return max_len;
    }
};