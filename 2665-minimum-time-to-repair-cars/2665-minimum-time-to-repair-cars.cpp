class Solution {
public:
bool isValid(vector<int>& ranks, long long cars,long long mid,int n){
   long long cnt=0;
   for(int i=0;i<n;i++){
      cnt+=(1ll)*sqrt(mid/ranks[i]);
   }
   return cnt>=cars;
}
    long long repairCars(vector<int>& ranks, int cars) {
        int n=ranks.size();
        long long l=1,r=1ll*(*min_element(begin(ranks),end(ranks))*(1ll)*cars*cars);
        long long res=0;
        while(l<=r){
           long long mid=l+(r-l)/2;
           if(isValid(ranks,cars,mid,n)){
              res=mid;
              r=mid-1;
           }else{
            l=mid+1;
           }
        }
        return res;
    }
};