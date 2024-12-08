class Solution {
public:
int n;
int t[100001][3];
int binarySearch(vector<vector<int>>& events,int endTime){
    int l=0;
    int r=n-1;
    int result=n;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(events[mid][0]>endTime){
            result=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return result;
}
   int solver(vector<vector<int>>& events,int i,int count){
   if(count==2 || i>=n) return 0;

   if(t[i][count]!=-1) return t[i][count];
   int nextvalidEventIndex=binarySearch(events,events[i][1]);
   int take=events[i][2]+solver(events,nextvalidEventIndex,count+1);

   int not_take=solver(events,i+1,count);
   return t[i][count]=max(take,not_take);
   }
    int maxTwoEvents(vector<vector<int>>& events) {
        n=events.size();
        sort(begin(events),end(events));
        int count=0;
        memset(t,-1,sizeof(t));
        return solver(events,0,count);
    }
};