class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int> map;
        for(int i=0;i<n;i++){
            int remain=target-nums[i];
            if(map.find(remain)!=map.end()){
                return {map[remain],i};
            }
            else map[nums[i]]=i;
        }
        return {};
    }
};