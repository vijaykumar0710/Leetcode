class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){ 
            pq.push({nums[i],i});
          }
          unordered_set<int>st;
            st.insert((pq.top().second)+1);
            st.insert((pq.top().second)-1);
            long long sum=pq.top().first;
            pq.pop();
          while(!pq.empty()){
            if(st.find(pq.top().second)==st.end()){
                sum+=pq.top().first;
                st.insert((pq.top().second)+1);
                st.insert((pq.top().second)-1);
            }
            pq.pop();
        }
        return sum;
    }
};