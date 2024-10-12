class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int i=0,j=i+1;
        int group=0;
        sort(begin(intervals),end(intervals));
        priority_queue<int,vector<int>,greater<int>>pq;
        pq.push(intervals[0][1]);
        for(int i=1;i<n;i++){
            int start=intervals[i][0];
            if(pq.top()<start){
                 pq.pop();
                 pq.push(intervals[i][1]);
            }else{  
                pq.push(intervals[i][1]);
            }
        }
        return pq.size();
    }
};