class Solution {
public:
const int MOD=1e9+7; 
    int countHomogenous(string s) {
        int n=s.size();
        vector<int>group;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                cnt++;
            }else{
                group.push_back(cnt);
                cnt=1;
            }
        }
        group.push_back(cnt);
        long long res=0;
        for(auto &n:group){
            res=(res+(n*1LL*(n+1))/2)%MOD;
        }
        return res;
    }
};