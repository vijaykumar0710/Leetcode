class Solution {
public:
int t[101][10001];
 int MCM(int eggs,int floors){
        if(floors==0 || floors==1 || eggs==1) return t[eggs][floors]=floors;
    
        if(t[eggs][floors]!=-1) return t[eggs][floors];

          int l=1,h=floors;
          int mn=INT_MAX;
          while(l<=h) {
              int mid=l+(h-l)/2;
              int a=MCM(eggs-1,mid-1);
              int b=MCM(eggs,floors-mid);
              int x=max(a,b) + 1;
              mn=min(mn,x);
              if(a>b) h=mid-1;
              else l=mid+1;
          }
         t[eggs][floors]=mn;   
        return t[eggs][floors];
    } 
    int superEggDrop(int k, int n) {
        memset(t,-1,sizeof(t));
        return MCM(k,n);
    }
};