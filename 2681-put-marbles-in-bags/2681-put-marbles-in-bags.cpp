class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        priority_queue<long long >maxPq;
        priority_queue<long long,vector<long long>,greater<long long>>minPq;
       unsigned long long sum=0;
        for(int i=0;i<n-1;i++){
           sum=(long long)weights[i]+(long long)weights[i+1];
            maxPq.push(sum);
            minPq.push(sum);
        }
        long long maxi=0,mini=0;
         for(int i = 0; i < k - 1; i++) {
            maxi += maxPq.top();
            maxPq.pop();
            mini += minPq.top();
            minPq.pop();
        }
        return maxi-mini;
    }
};