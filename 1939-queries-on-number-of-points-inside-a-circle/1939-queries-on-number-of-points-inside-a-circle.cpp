class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int>res;
        for(auto &query:queries){
            int x=query[0];
            int y=query[1];
            int r=query[2];
            int cnt=0;
            for(auto &point:points){
                int h=point[0];
                int k=point[1];
                if(((x-h)*(x-h)+(y-k)*(y-k))<=r*r) cnt++;
            }
            res.push_back(cnt);
        }
        return res;
    }
};