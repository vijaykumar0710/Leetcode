class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
       int n=meetings.size();
        sort(begin(meetings),end(meetings));
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
        if(ans.empty() || ans.back()[1]<meetings[i][0]){
            ans.push_back(meetings[i]);
            }else{
                ans.back()[1]=max(ans.back()[1],meetings[i][1]);
            }
        }
        int sum=0;
        for(auto &meet:ans){
          sum+=(meet[1]-meet[0]+1);
        }
        return days-sum;
    }
};
