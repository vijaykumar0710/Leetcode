class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        long long total=prefix[n-1];
        unordered_map<long long,int>right;
        for(int i=0;i<n-1;i++){
            right[prefix[i]]++;
        }
        int maxWays=0;
        if(total%2==0){
            maxWays=right[total/2]; //prefix[i]==total-prefix[i]=>prefix[i]=total/2
        }
        unordered_map<long long,int>left;
        for(int i=0;i<n;i++){
            long long delta=(long long)k-nums[i];
            long long newTotal=total+delta;
            if(newTotal%2==0){
                long long newTarget=newTotal/2;
                int ways=0;
                ways+=left[newTarget];
                ways+=right[newTarget-delta];
                maxWays=max(maxWays,ways);
            }
            if(i<n-1){
                right[prefix[i]]--;
                left[prefix[i]]++;
            }
        }
        return maxWays;
    }
};