class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int,vector<int>> pq;
        for(auto &num:nums){
            pq.push(num);
        }
        long long score=0;
        for(int i=0;i<k;i++){
            int x=pq.top();
            score+=x;
            pq.pop();
            if(x%3==0){
                pq.push(x/3);
            }
            else{
                pq.push(x/3+1);
            }
        }
        return score;
    }
};