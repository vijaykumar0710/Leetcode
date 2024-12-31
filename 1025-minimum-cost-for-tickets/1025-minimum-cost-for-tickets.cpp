class Solution {
public:
int n;
int t[366];
int solve(vector<int>& days, vector<int>& costs,int i){
    if(i>=n) return 0;

     if(t[i]!=-1) return t[i];

    int cost_1=costs[0]+solve(days,costs,i+1);

    int j=i;
    int max_day=days[i]+7;
    while(j<n && days[j]<max_day){
        j++;
    }
     int cost_7=costs[1]+solve(days,costs,j);

     j=i;
    max_day=days[i]+30;
    while(j<n && days[j]<max_day){
        j++;
    }
     int cost_30=costs[2]+solve(days,costs,j);

     return t[i]=min({cost_1,cost_7,cost_30});
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n=days.size();
        memset(t,-1,sizeof(t));
        return solve(days,costs,0);
    }
};