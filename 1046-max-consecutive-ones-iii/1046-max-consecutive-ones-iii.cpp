class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int flips=0,i=0,j=0;
        int maxLen=INT_MIN,len=INT_MIN;
          while(j<n){
            if(nums[j]==1) j++;
            else{  //nums[j]==0
                if(flips<k){
                    flips++;
                    j++;
                }else{    //flips==k
                // calculate length
                len=j-i;
                maxLen=max(maxLen,len);
                //i ko just aage wale 0 se ek idx aage le jao
                  while(nums[i]==1) i++; // after this 100% nums[i]=0
                  i++;
                  j++;
                }
             }
          }
           len=j-i;
           maxLen=max(maxLen,len);
          return maxLen;
    }
};