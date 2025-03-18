class Solution {
public:
typedef pair<int,pair<int,int>>pp;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        priority_queue<pp>pq;
        for(auto point:points){
            int x=point[0];
            int y=point[1];
            pq.push({(x*x+y*y),{x,y}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>>res;
        while(pq.size()){
            auto pair=pq.top().second;
            res.push_back({pair.first,pair.second});
            pq.pop();
        }
        return res;
    }
};