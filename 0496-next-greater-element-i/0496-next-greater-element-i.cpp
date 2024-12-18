class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int i=0,j=0;
        vector<int>nextGreater(n,-1);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums2[j] > nums2[i]) {
                    nextGreater[i] = nums2[j];
                    break;
                }
            }
        }

       for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (nums1[i] == nums2[j]) {
                    nums1[i] = nextGreater[j];
                    break;
                }
            }
        }
       return nums1;
    }
};