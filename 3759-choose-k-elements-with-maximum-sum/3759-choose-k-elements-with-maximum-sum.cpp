class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<vector<int>> arr(n);
        for(int i=0; i<n; i++) {
            arr[i]={nums1[i], i,nums2[i]}; 
        }
        sort(arr.begin(), arr.end());

        vector<long long> res(n, 0);
      priority_queue<long long,vector<long long>,greater<long long>>pq;
      long long sum=0;
      for(int i=0;i<n;i++){
        if(i>0 && arr[i][0]==arr[i-1][0]){
            res[arr[i][1]]=res[arr[i-1][1]];
        }else{ 
         res[arr[i][1]]=sum;
        }
         pq.push(arr[i][2]);
         sum+=arr[i][2];
         if(pq.size()>k){
            sum-=pq.top();
            pq.pop();
         }
      }
      return res;
    }
};
