class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        int no_k=count(nums.begin(),nums.end(),k);
        int mx=0;
        for(int i=1;i<=50;i++){
          if(i==k) continue;
          int s=0,l=0;
          for(auto &it:nums){
            if(i==it) s++;
            else if(it==k) s--;
            if(s<0) s=0;
            l=max(l,s);
          }
          mx=max(mx,l);
        }
        return no_k+mx;
    }
};