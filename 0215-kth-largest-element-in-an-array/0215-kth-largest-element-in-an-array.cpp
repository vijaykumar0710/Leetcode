class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>minPq;
       for(auto &num:nums){
        minPq.push(num);
        if(minPq.size()>k)
           minPq.pop();
       } 
       return minPq.top();
    }
};