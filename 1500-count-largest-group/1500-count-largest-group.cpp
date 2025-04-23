class Solution {
public:
    int countLargestGroup(int n) {
       vector<long long>vec(n+1,0);
       for(int i=1;i<=n;i++){
        long long sum=0;
        int m=i;
        while(m){
          sum+=(m%10);
          m/=10;
          }
          vec[sum]++;
       }
       int max_size=*max_element(vec.begin(),vec.end());
       int cnt=0;
       for(int i=0;i<vec.size();i++){
        if(vec[i]==max_size){
            cnt++;
        }
       }
       return cnt;
    }
};