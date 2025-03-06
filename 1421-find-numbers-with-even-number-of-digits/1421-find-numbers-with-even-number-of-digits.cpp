class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int even=0;
        for(auto &n:nums){ 
            int cnt=0;
        while(n){
           n%10;
           n/=10;
           cnt++;
          }
          if(cnt%2==0){
            even++;
          }
        }
        return even;
    }
};