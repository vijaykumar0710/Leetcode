class Solution {
public:
typedef pair<int,pair<int,int>> pip;
    vector<int> smallestRange(vector<vector<int>>& arr) {
        priority_queue<pip,vector<pip>,greater<pip>> pq;
        int mx=INT_MIN;
        for(int i=0;i<arr.size();i++){
            mx=max(mx,arr[i][0]);
            pq.push({arr[i][0],{i,0}});
        }
        int mn=pq.top().first;
        int start=mn,end=mx;
        while(true){
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(col==arr[row].size()-1) break;
            pq.push({arr[row][col+1],{row,col+1}});
            mx=max(mx,arr[row][col+1]);
            mn=pq.top().first;
          if(mx-mn<end-start){
            end=mx;
            start=mn;
          }
        }
        return {start,end};
    }
};