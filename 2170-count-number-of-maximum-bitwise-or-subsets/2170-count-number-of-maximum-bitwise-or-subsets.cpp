class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int maxim=nums[0];
        for(auto &num:nums){
          maxim=(maxim | num);
        }
        int subsets=1<<n;
        vector<vector<int>>res;
        for(int num=0;num<subsets;num++){
          vector<int>vec;
          for(int i=0;i<n;i++){
            if((num &(1<<i))){
                vec.push_back(nums[i]);
            }
          }
          res.push_back(vec);
        }

          int count=0;
        for(int vec=1;vec<res.size();vec++){
            int biti=res[vec][0];
          for(auto &num:res[vec]){
              biti=(biti | num);
           }
          if(biti==maxim){
            count++;
          }
        }
        return count;
    }
};