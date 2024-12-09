class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        int XOR=nums[0];
        for(int i=1;i<n;i++){
          if((XOR^nums[i])%2==0) return false;
          XOR=nums[i];
        }
        return true;
    }
};