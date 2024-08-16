class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto &num:nums){
            pq.push(num);
        }
        vector<int>arr;
        while(!pq.empty()){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            arr.push_back(y);
            arr.push_back(x);
        }
        return arr;
    }
};