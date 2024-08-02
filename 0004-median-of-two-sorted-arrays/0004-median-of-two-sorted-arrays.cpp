class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<m;i++){
            pq.push(nums1[i]);
        }
         for(int i=0;i<n;i++){
            pq.push(nums2[i]);
        }
        vector<int> vec;
        while(!pq.empty()){
          vec.push_back(pq.top());
          pq.pop();
        }
        if((m+n)%2!=0){
            return vec[(m+n)/2];
        }else{
            double ans=(vec[(m+n)/2]+vec[((m+n)/2)-1])/2.0;
            return ans;
        }
        return -1;
    }
};