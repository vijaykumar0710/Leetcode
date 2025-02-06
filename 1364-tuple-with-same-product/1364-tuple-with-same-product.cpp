class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
               long long pro=nums[i]*nums[j];
               mp[pro]++;
            }
        }
        int res=0;
      for(auto [_,freq]:mp){
          if(freq>=2){
            int temp=freq*(freq-1)/2;
            res+=temp*8;
          }
      }
      return res;
    }
};