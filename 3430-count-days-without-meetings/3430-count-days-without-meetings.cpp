class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
       int n=meetings.size();
        sort(begin(meetings),end(meetings));
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            int start=meetings[i][0];
            int end=meetings[i][1];
            if(!ans.empty() && end<=ans.back()[1]){
                continue;
            }
            for(int j=i+1;j<n;j++){
                if(meetings[j][0]<=end){
                    end=max(end,meetings[j][1]);
                }
                else{
                    break;
                }
            }
            ans.push_back({start,end});
        }
        int sum=0;
        for(auto &meet:ans){
          sum+=(meet[1]-meet[0]+1);
        }
        return days-sum;
    }
};
