class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
          //t[i]=max. stolen money till ith house
          //no house:i=0
          int prev=nums[0];
          //1 house:i=1
          int prevPrev=0;

          for(int i=2;i<=n;i++){
            int steal=nums[i-1]+prevPrev;
            int skip=prev;
            int temp=max(steal,skip);
            prevPrev=prev;
            prev=temp;
          } 
          return prev;
    }
};