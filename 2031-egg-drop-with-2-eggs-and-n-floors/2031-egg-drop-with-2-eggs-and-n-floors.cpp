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
        int temp=1+max(MCM(egg-1,k-1),MCM(egg,floor-k));
        mini=min(mini,temp);
    }
    return t[egg][floor]=mini;
}
    int twoEggDrop(int n) {
        memset(t,-1,sizeof(t));
        return MCM(2,n);
    }
};