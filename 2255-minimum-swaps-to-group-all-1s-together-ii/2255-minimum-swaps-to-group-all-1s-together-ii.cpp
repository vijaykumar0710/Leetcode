class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int oneCount = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) oneCount++;
        }
     int i=0,j=0;

     int currOnes=0;
     int maxCount=0;
     while(j<2*n){
        if(nums[j%n]==1){
            currOnes++;
        }
        if(j-i+1>oneCount){
           currOnes-=nums[i%n];
           i++; 
        }
        maxCount=max(maxCount,currOnes);
        j++;
     }  
         return oneCount-maxCount;
    }
};
