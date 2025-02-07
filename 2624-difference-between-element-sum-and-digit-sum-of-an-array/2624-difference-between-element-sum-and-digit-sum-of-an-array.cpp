class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int n=nums.size();
        int sumEle=0;
        int sumDig=0;
        for(int i=0;i<n;i++){
            sumEle+=nums[i];
            int p=nums[i],digit=0;
            while(p){
                digit+=p%10;
                p/=10;
            }
            sumDig+=digit;
        }
        return abs(sumEle-sumDig);
    }
};