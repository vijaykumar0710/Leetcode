class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int,int>mp;
        int maxi=0;
        for(int i=lowLimit;i<=highLimit;i++){
            int sum=0,n=i;
            while(n){
                sum+=n%10;
                n/=10;
            }
            mp[sum]++;
            maxi=max(maxi,mp[sum]);
        }
        return maxi;
    }
};