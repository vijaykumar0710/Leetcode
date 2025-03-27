class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp1,mp2;
        for(auto &num:nums){
            mp2[num]++;
        }
        for(int i=0;i<n-1;i++){
            mp1[nums[i]]++;
            mp2[nums[i]]--;
            if(mp1[nums[i]]>(i+1)/2 && mp2[nums[i]]>(n-1-i)/2)
                  return i;
        }
        return -1;
    }
};