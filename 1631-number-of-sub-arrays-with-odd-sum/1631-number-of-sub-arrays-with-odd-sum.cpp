class Solution {
public:
int MOD=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<int>prefix_sum(n,0);
        prefix_sum[0]=arr[0];
        for(int i=1;i<n;i++){
        prefix_sum[i]=arr[i]+prefix_sum[i-1];
        }
        int cnt=0;
        int even=1,odd=0;
       for(int i=0;i<n;i++){
           if(prefix_sum[i]%2==0){
            even++;
            cnt=(cnt+odd)%MOD;
           }else{
            odd++;
            cnt=(cnt+even)%MOD;
           }
       }
        return cnt;
    }
};