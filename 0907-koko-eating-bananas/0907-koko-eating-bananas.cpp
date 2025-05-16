class Solution {
public:
bool isValid(vector<int>&piles,long long mid,long long h,int n){
    long long hour=0;
    for(auto &pile:piles){ 
        hour+=pile/mid;
        if(pile%mid!=0) hour++;
    }
    return hour<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1,r=*max_element(piles.begin(),piles.end());
        int res=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(piles,mid,h,n)){
                res=mid;
                r=mid-1;
            }else l=mid+1;
        }
        return res;
    }
};