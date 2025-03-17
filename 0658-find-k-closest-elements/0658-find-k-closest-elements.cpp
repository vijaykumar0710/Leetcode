class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        priority_queue<pair<int,int>>pq;
        vector<int>res;
        for(int i=0;i<n;i++){
           pq.push({abs(x-arr[i]),arr[i]});
           if(pq.size()>k){
            pq.pop();
           }
        }
        while(pq.size()>0){
            res.push_back(pq.top().second);
            pq.pop();
        }
        sort(begin(res),end(res));
        return res;
    }
};