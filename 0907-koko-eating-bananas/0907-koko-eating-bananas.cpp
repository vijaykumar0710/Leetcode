class Solution {
public:
bool isValid(vector<int>& piles,  long long mid,  long long h, int n){
   long long cnt=0;
 for(int i=0;i<n;i++){ 
 cnt+=piles[i]/mid;
 if(piles[i]%mid!=0)
     cnt++;
 }
 return cnt<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
          long long l=1,r=*max_element(begin(piles),end(piles));
          long long res=0;
        while(l<=r){
             long long mid=l+(r-l)/2;
            if(isValid(piles,mid,h,n)){
                res=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        } 
        return res;
    }
};