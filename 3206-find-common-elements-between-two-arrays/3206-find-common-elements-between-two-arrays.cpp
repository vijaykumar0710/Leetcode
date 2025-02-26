class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        for(auto num:nums1){
            mp1[num]++;
        }
        for(auto num:nums2){
            mp2[num]++;
        }
        vector<int>ans(2);
        int sum1=0,sum2=0;
        for(auto [num,freq]:mp1){
           if(mp2.find(num)!=mp2.end()){
              sum1+=freq;
           }
        }
        ans[0]=sum1;

        for(auto [num,freq]:mp2){
           if(mp1.find(num)!=mp1.end()){
              sum2+=freq;
           }
        }
        ans[1]=sum2;
        return ans;
    }
};