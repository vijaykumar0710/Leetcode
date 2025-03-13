class Solution {
public:
int n;
bool check(vector<int>& nums,vector<vector<int>>& queries,int k){
vector<unsigned long long>diffArr(n,0);
        for(int i=0;i<k;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int val=queries[i][2];
             diffArr[l]+=val;
             if(r+1<n)
             diffArr[r+1]-=val; 
        }
 vector<unsigned long long> prefix(n, 0);
 prefix[0] = diffArr[0];
 for (int i = 1; i < n; i++) {
 prefix[i] = prefix[i - 1] + diffArr[i];
     }
 for(int i=0;i<n;i++){
   if(prefix[i]<nums[i]){
        return false;
      }
   } 
   return true;
}
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
       n=nums.size();
      int l=0,r=queries.size();
      int ans=-1;
      while(l<=r){
        int mid=l+(r-l)/2;
        if(check(nums,queries,mid)){
          ans=mid;
          r=mid-1;
        }else{
            l=mid+1;
        }
      }
      return ans;
    }
};