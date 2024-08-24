class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
       for(int i=0;i<n;i++){
        int x=mp[nums[i]];
        if(x==1){
            return nums[i];
        }
       }
       return -1;
    }
};