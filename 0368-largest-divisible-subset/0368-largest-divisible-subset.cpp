class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       int n=nums.size();
       vector<int>t(n,1);
       vector<int>prevIdx(n,-1);
       int maxLis=1;
       int LISidx=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]%nums[j]==0 || nums[j]%nums[i]==0){
                if(t[j]+1>t[i]){
                    t[i]=t[j]+1;
                    prevIdx[i]=j;
                    if(maxLis<t[i]){
                        maxLis=t[i];
                        LISidx=i;
                    }
                }
            }
        }
       }
       vector<int>res;
       while(LISidx!=-1){
        res.push_back(nums[LISidx]);
        LISidx=prevIdx[LISidx];
       }
       reverse(res.begin(),res.end());
       return res;
    }
};