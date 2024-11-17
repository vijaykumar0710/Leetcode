class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
         deque<int>deq;
        vector<long long> cummulativeSum(n,0);
        int result=INT_MAX;
        int j=0;
        while(j<n){
            if(j==0){
                cummulativeSum[j]=nums[j];
            }else{
                cummulativeSum[j]=cummulativeSum[j-1]+nums[j];
            }
            if(cummulativeSum[j]>=k){
                result=min(result,j+1);
            }
            while(!deq.empty() && cummulativeSum[j]-cummulativeSum[deq.front()]>=k){
                result=min(result,j-deq.front());
                deq.pop_front();
            }
            while(!deq.empty() && cummulativeSum[j]<=cummulativeSum[deq.back()]){
                deq.pop_back();
            }
            deq.push_back(j);
            j++;
        }
        return result==INT_MAX?-1:result;
    }
};