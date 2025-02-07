class Solution {
public:
bool checkDouble(int num){
    if(num/10!=0) return true;
    return false;
}
    bool canAliceWin(vector<int>& nums) {
        int n=nums.size();
        int single=0,doubly=0;
        for(int i=0;i<n;i++){
            if(checkDouble(nums[i])){
                doubly+=nums[i];
            }else{
                single+=nums[i];
            }
        }
        return single!=doubly;
    }
};