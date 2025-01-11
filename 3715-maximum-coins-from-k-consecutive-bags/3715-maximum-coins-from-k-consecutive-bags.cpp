class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        long long ans=0,sum=0;
        for(int l=0,r=0;r<n;r++){
            int end=coins[r][1],start=end-k+1;
            sum+=1ll*(coins[r][1]-coins[r][0]+1)*coins[r][2];
            while(l<=r && start>coins[l][0]){
                sum-=1ll*(coins[l][1]-coins[l][0]+1)*coins[l][2];
                l++;
            }
            if(l>0 && start<=coins[l-1][1]){
                sum+=1ll*(coins[l-1][1]-start+1)*coins[l-1][2];
            }
            ans=max(ans,sum);
            if(l>0 && start<=coins[l-1][1]){
                sum-=1ll*(coins[l-1][1]-start+1)*coins[l-1][2];
            }
        }
        sum=0;
        for(int l=n-1,r=n-1;l>=0;l--){
            int start=coins[l][0],end=start+k-1;
            sum+=1ll*(coins[l][1]-coins[l][0]+1)*coins[l][2];
            while(l<=r && end<coins[r][1]){
                sum-=1ll*(coins[r][1]-coins[r][0]+1)*coins[r][2];
                r--;
            }
            if(r<n-1 && end>=coins[r+1][0]){
                sum+=1ll*(end-coins[r+1][0]+1)*coins[r+1][2];
            }
            ans=max(ans,sum);
            if(r<n-1 && end>=coins[r+1][0]){
                sum-=1ll*(end-coins[r+1][0]+1)*coins[r+1][2];
            }
        }
        return ans;
    }
};