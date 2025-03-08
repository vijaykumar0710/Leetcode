class Solution {
public:
int t[3][1001];
int MCM(int egg,int floor){
    if(floor==0 || floor==1)
       return floor;
    if(egg==1)
      return floor;

    if(t[egg][floor]!=-1)
        return t[egg][floor];

    int mini=INT_MAX;
    for(int k=1;k<=floor;k++){
        int low,high;
        if(t[egg-1][k-1]!=-1){
            low=t[egg-1][k-1];
        }else{
            low=MCM(egg-1,k-1);
            t[egg-1][k-1]=low;
        }
        if(t[egg][floor-k]!=-1){
            high=t[egg][floor-k];
        }else{
            high=MCM(egg,floor-k);
            t[egg][floor-k]=high;
        }
        int temp=1+max(low,high);
        mini=min(mini,temp);
    }
    return t[egg][floor]=mini;
}
    int twoEggDrop(int n) {
        memset(t,-1,sizeof(t));
        return MCM(2,n);
    }
};