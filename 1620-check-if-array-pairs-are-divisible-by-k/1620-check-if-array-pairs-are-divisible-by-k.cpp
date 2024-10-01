class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int ele : arr){
            ele=((ele%k)+k)%k;
            mp[ele]++;
        }
        if(mp.find(0)!=mp.end()){
        if(mp[0]%2!=0) return false;
        mp.erase(0);
        }
        for(auto x:mp){
            int ele=x.first;
            int rem=k-ele;
            if(mp.find(rem)==mp.end()) return false;
            if(mp[ele]!=mp[rem]) return false;
        }
        return true;
    }
};