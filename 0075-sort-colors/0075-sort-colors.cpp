class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int noZ=0,noO=0,noT=0;
        for(int i=0;i<n;i++){
         if(nums[i]==0) noZ++;
         if(nums[i]==1) noO++;
         if(nums[i]==2) noT++;
        }
           for(int j=0;j<noZ;j++){
            nums[j]=0;
        }
        for(int j=noZ;j<noO+noZ;j++){
            nums[j]=1;
        }
        for(int j=noO+noZ;j<n;j++){
            nums[j]=2;
        }
    }
};