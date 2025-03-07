class Solution {
public:
vector<int>res;
void solve(int N){
     vector<bool>isPrime(N+1,true);
        for(int i=2;i<=sqrt(N);i++){
            if(isPrime[i]==true){
              for(int j=2;i*j<=N;j++){
                  isPrime[i*j]=false;
              }
            }
        }
        for(int i=2;i<=N;i++){
            if(isPrime[i]==true){
              res.push_back(i);
            }
        }
}
    vector<int> closestPrimes(int left, int right) {
        solve(right);
        vector<int>vec;
        for(auto &num:res){
            if(num>=left){
                vec.push_back(num);
            }
        }
        if(vec.size()<2) return {-1,-1};
        vector<int>ans(2);
        ans[0]=vec[0];
        ans[1]=vec[1];
        int mini=vec[1]-vec[0];
        for(int i=2;i<vec.size();i++){
           if(mini>(vec[i]-vec[i-1])){
            mini=vec[i]-vec[i-1];
            ans[0]=vec[i-1];
            ans[1]=vec[i];
           }
        }
        return ans;
    }
};