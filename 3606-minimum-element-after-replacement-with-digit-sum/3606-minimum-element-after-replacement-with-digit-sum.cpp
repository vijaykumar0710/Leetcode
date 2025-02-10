class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(auto &num:nums){
            int n=num;
            int sum=0;
            while(n){
             sum+=n%10;
             n/=10;
            }
           mini=min(mini,sum);
        }
        return mini;
    }
};