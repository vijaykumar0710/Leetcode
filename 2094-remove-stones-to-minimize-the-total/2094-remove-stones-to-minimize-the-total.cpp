class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n=piles.size();
        priority_queue<long>pq;
        long rem_piles=0;
        for(auto &pile:piles){
            pq.push(pile);
        }
        for(int i=0;i<k;i++){
            long x=pq.top()-(pq.top()/2);
            pq.pop();
            pq.push(x);
        }
        while(!pq.empty()){
            rem_piles+=pq.top();
            pq.pop();
        }
        return rem_piles;
    }
};