class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        priority_queue<int>pq;
        for(auto &pile:piles){
          pq.push(pile);
        }
        int alice=0,bob=0;
        while(!pq.empty()){
             alice+=pq.top();
             pq.pop();
             bob+=pq.top();
             pq.pop();
        }
        return alice>bob;
    }
};