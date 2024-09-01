class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string>res(n);
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({score[i],i});
        }
        for(int i=1;i<=n;i++){
            int idx=pq.top().second;
            pq.pop();
            
            if(i==1){
                res[idx]="Gold Medal";
            }else if(i==2){
                res[idx]="Silver Medal";
            }else if(i==3){
                res[idx]="Bronze Medal";
            }else{
                res[idx]=to_string(i);
            }
        }
        return res;
    }
};