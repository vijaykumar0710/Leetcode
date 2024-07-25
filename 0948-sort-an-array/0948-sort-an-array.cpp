class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto &ele:nums){
            pq.push(ele);
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};