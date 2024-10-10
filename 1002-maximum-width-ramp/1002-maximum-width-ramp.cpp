class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();

        vector<int>indx(n);
        for(int i=0;i<n;i++){
            indx[i]=i;
        }

        sort(indx.begin(),indx.end(),[&](int i,int j){
             return nums[i]!=nums[j] ? nums[i]<nums[j]:i<j;
        });

        int minidx=n;
        int maxwidth=0;
        for(int i=0;i<n;i++){
            maxwidth=max(maxwidth,indx[i]-minidx);
            minidx=min(minidx,indx[i]);
        }
        return maxwidth;
    }
};