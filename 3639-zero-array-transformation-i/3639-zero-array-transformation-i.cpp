class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>diff(n+1,0);
        for(auto &query:queries){
            int s=query[0];
            int e=query[1];
            diff[s]-=1;
            diff[e+1]+=1;
        }
      vector<int>diffArr(n,0);
      diffArr[0]=diff[0];
      for(int i=1;i<n;i++){
        diffArr[i]+=diffArr[i-1]+diff[i];
      }
      for(int i=0;i<n;i++){
        if(abs(diffArr[i])<nums[i]) return false;
      }
      return true;
    }
};