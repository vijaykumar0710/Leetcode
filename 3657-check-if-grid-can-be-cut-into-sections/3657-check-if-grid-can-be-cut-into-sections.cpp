class Solution {
public:
bool merge(vector<vector<int>>&intervals){
     int n=intervals.size();
        sort(begin(intervals),end(intervals));
        vector<vector<int>>res;
        int prevStart=intervals[0][0];
        int prevEnd=intervals[0][1];
        for(int i=1;i<n;i++){
            int currStart=intervals[i][0];
            int currEnd=intervals[i][1];
            if(currStart<prevEnd){
                currEnd=max(prevEnd,currEnd);
            }else{
                res.push_back({prevStart,prevEnd});
                prevStart=currStart;
            }
            prevEnd=max(prevEnd,currEnd);
        }
         res.push_back({prevStart,prevEnd});
        return res.size()>=3;
}
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>vec1,vec2;
        for(auto &vec:rectangles){
            vec1.push_back({vec[0],vec[2]});
            vec2.push_back({vec[1],vec[3]});
        }
        return merge(vec1)||merge(vec2);
    }
};