class Solution {
public:
int t[3][1001];
int MCM(int egg,int floor){
    if(floor==0 || floor==1 || egg==1)
       return t[egg][floor]=floor;
    
    if(t[egg][floor]!=-1)
        return t[egg][floor];

    int mini=INT_MAX;
    int l=1,r=floor;
    while(l<=r){
      int mid=l+(r-l)/2;
      int below=MCM(egg-1,mid-1);
      int up=MCM(egg,floor-mid);
      int temp=1+max(below,up);
      mini=min(mini,temp);
      if(below>up) r=mid-1;
      else l=mid+1;
    }   
     t[egg][floor]=mini;
     return mini;
}
    int twoEggDrop(int n) {
        memset(t,-1,sizeof(t));
        return MCM(2,n);
    }
};