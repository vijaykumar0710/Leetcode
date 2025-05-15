class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto low=lower_bound(nums.begin(),nums.end(),target);
        auto up=upper_bound(nums.begin(),nums.end(),target);
        if(low==nums.end() || *low!=target) return {-1,-1};
        int first=low-nums.begin(); //given index
        int second=up-nums.begin()-1; //given index
        return {first,second};
    }
};