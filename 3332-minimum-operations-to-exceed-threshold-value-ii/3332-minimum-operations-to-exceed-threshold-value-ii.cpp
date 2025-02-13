class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>minPq;
        for(auto num:nums){
            minPq.push(num);
        }
        int minOperations=0;
        while(minPq.top()<k){
            minOperations++;
            long long x=minPq.top();
            minPq.pop();
            long long y=minPq.top();
            minPq.pop();
            long long operation=min(x, y) * 2 + max(x, y);
            minPq.push(operation);
        }
        return minOperations;
    }
};