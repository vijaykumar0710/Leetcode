class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>maxR(n);
        maxR[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
           maxR[i]=max(maxR[i+1],height[i]);
        }
       vector<int>maxL(n);
       maxL[0]=height[0];
        for(int i=1;i<n;i++){
            maxL[i]=max(maxL[i-1],height[i]);
        }
        int maxWater=0;
      for(int i=0;i<n;i++){
         int water=min(maxR[i],maxL[i])-height[i];
         maxWater+=water;
      }
      return maxWater;
    }
};