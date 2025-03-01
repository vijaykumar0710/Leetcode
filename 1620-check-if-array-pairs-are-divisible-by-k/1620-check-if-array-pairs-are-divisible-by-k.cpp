class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int m=arr.size();
        unordered_map<int,int>mp;
        for(auto &num:arr){
            mp[((num % k) + k) % k]++;
        }
        for(auto &[rem,freq]:mp){
            if(rem==0) {
                if(freq%2!=0)
                return false;
            }
            else{
                if(mp[k-rem]!=mp[rem]){
                    return false;
                }
            }
        }
        return true;
    }
};