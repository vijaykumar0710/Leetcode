class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n=gifts.size();
        priority_queue<long>pq;
        long rem_gifts=0;
        for(auto &gift:gifts){
            pq.push(gift);
        }
        for(int i=0;i<k;i++){
            long x=sqrt(pq.top());
            pq.pop();
            pq.push(x);
        }
        while(!pq.empty()){
            rem_gifts+=pq.top();
            pq.pop();
        }
        return rem_gifts;
    }
};