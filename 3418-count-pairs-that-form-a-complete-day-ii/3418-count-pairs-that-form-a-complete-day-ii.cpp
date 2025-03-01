class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
     vector<long long>vec;
    for (int num : hours) {
        vec.push_back(num%24);
    }
    unordered_map<long long,long long>mp;
    int n=vec.size();
    long long cnt=0;
    for(int i=n-1;i>=0;i--){
      if(vec[i]!=0 && mp.find(24-vec[i])!=mp.end()){
        cnt+=mp[24-vec[i]];
       }
      if(vec[i]==0 && mp.find(vec[i])!=mp.end()){
        cnt+=mp[vec[i]];
       }
       mp[vec[i]]++;
      }
      return cnt;
    }
};