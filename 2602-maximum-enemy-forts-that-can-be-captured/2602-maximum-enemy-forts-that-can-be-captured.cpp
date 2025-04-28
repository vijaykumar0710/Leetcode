class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n=forts.size();
       vector<pair<int,int>>group;
       int cnt=1;
       int i=1;
       for(;i<n;i++){
        if(forts[i]==forts[i-1]){
            cnt++;
        }else{
            group.push_back({forts[i-1],cnt});
            cnt=1;
         }
       }
       group.push_back({forts[i-1],cnt});
       int m=group.size();
       int res=0;
       for(int i=0;i<m;i++){
        if(i+2<m && group[i].first==1&&group[i+2].first==-1){
            res=max(res,group[i+1].second);
        }
        if(i+2<m && group[i].first==-1&&group[i+2].first==1){
            res=max(res,group[i+1].second);
        }
       }
       return res;
    }
};