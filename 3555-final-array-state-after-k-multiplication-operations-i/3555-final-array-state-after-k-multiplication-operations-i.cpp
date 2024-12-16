class Solution {
public:
typedef pair<int,int>pi;
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pi,vector<pi>,greater<pi>> min_pq;
        for(int i=0;i<nums.size();i++){
          min_pq.push({nums[i],i});
        }
        while(k>0){
         auto [num,idx]=min_pq.top();
         min_pq.pop();
         min_pq.push({multiplier*num,idx});
         nums[idx]=multiplier*num;
         k--;
        }
        return nums;
    }
};