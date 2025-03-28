class Solution {
public:
vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
   vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    int k=queries.size();
    int m=grid.size();
    int n=grid[0].size();
     vector<int>res(k);
     vector<pair<int,int>>sortqueries;
       for(int i=0;i<k;i++){
        sortqueries.push_back({queries[i],i});
       }
       sort(begin(sortqueries),end(sortqueries));
      priority_queue<vector<int>, vector<vector<int>>, greater<>>minpq;
       vector<vector<bool>>visited(m,vector<bool>(n,false));
       int cnt=0;
       minpq.push({grid[0][0],0,0});
       visited[0][0]=true;
   
   for(int i=0;i<k;i++){
    int val=sortqueries[i].first;
    int idx=sortqueries[i].second;
   while(!minpq.empty() && minpq.top()[0]<val){
    int currRow=minpq.top()[1];
    int currCol=minpq.top()[2];
    minpq.pop();
    cnt++;
      for(auto &direction:directions){
        int newRow=currRow+direction[0];
        int newCol=currCol+direction[1];
        if(newRow>=0 && newRow<m && newCol>=0 && newCol<n && !visited[newRow][newCol]){
            minpq.push({grid[newRow][newCol],newRow,newCol});
            visited[newRow][newCol]=true;
        }
      }
    }
    res[idx]=cnt;
   }
   return res;
  }
};