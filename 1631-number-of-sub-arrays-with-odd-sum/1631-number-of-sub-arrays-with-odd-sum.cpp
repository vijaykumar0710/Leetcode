class Solution {
public:
int MOD=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
       int prefix_sum=0;
        int cnt=0;
        int even=1,odd=0;
       for(int i=0;i<n;i++){
        prefix_sum+=arr[i];
           if(prefix_sum%2==0){
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