class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
       for(int i=n-1;i>=0;i--){
        int m=nums[i];
          while(m){
            res.push_back(m%10);
            m/=10;
          }
       }
       reverse(res.begin(),res.end());
        return res;
    }
};