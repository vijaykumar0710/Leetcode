class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        int m=nums2.size();
        int good_pairs=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(nums1[j]%(nums2[i]*k)==0)good_pairs++;
            }
        }
        return good_pairs;
    }
};