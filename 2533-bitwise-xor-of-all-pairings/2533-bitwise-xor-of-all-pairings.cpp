class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        unordered_map<long,long>mp;
        for(int i=0;i<n1;i++){
            mp[nums1[i]]+=n2;
        }
        for(int i=0;i<n2;i++){
            mp[nums2[i]]+=n1;
        }
        long res=0;
        for(auto &[num,freq]:mp){
          if(freq%2!=0){
            res^=num;
          }
        }
        return res;
    }
};