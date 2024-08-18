class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jumps=0;
        int l=0,r=0;
         while(r<n-1){
            int farthest_go=0;
            for(int i=l;i<=r;i++){
                farthest_go=max(i+nums[i],farthest_go);
            }
            l=r+1;
            r=farthest_go;
             jumps++;
         }
        return jumps;
    }
};