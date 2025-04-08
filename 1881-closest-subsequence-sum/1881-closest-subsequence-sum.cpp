class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        int half=n/2;
        vector<int>leftSum,rightSum;

        for(int mask=0;mask<(1<<half);mask++){
            int sum=0;
            for(int j=0;j<half;j++){
                if(mask&(1<<j))
                  sum+=nums[j];
            }
            leftSum.push_back(sum);
        }

        for(int mask=0;mask<(1<<(n-half));mask++){
           int sum=0;
           for(int j=0;j<(n-half);j++){
            if(mask&(1<<j))
               sum+=nums[half+j];
           }
           rightSum.push_back(sum);
        }

    sort(rightSum.begin(),rightSum.end());

    int res=abs(goal);
    for(int x:leftSum){
       int rem=goal-x;
       auto it=lower_bound(rightSum.begin(),rightSum.end(),rem);

       if(it!=rightSum.end()){
           res=min(res,abs(x+*it-goal));
          }
       if(it!=rightSum.begin()){
          it--;
           res=min(res,abs(x+*it-goal));
          }
       }
       return res;
    }
};