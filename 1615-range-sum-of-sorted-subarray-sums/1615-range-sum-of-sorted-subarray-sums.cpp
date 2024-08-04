class Solution {
public:
    typedef pair<int,int> p;
    int M=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
         priority_queue<p,vector<p>,greater<p>>pq;
         for(int i=0;i<n;i++){
            pq.push({nums[i],i});
         }
         int result=0;
         for(int count=1;count<=right;count++){
        auto p=pq.top();
        pq.pop();

        int sum=p.first;
        int idx=p.second;

        if(count>=left){
            result=(result+sum)%M;
             }
             int new_idx=idx+1;
            //   p new_pair;
             if(new_idx<n){  
                // new_pair.first=sum+nums[new_idx];
                // new_pair.second=new_idx;
                pq.push({sum+nums[new_idx],new_idx});
             }
         }
         return result;
    }
};