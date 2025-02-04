class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool>res(n,0);
        res[0]=1;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
               if(res[j]==1 && j+nums[j]>=i){
                res[i]=1;
                break;
               }
            }
        }
        return res[n-1];
    }
};