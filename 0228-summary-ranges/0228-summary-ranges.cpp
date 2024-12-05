class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> vec;
        long long n=nums.size();
        if(n==0) return vec;
        long long i=0;
        long long st=nums[0];
        for(long long i=0;i<n;i++){
            if(i==n-1 || nums[i]+1!=nums[i+1]){ 
            if(nums[i]!=st){
            vec.push_back(to_string(st)+"->"+to_string(nums[i]));
            }else{
             vec.push_back(to_string(nums[i]));
               }
             if(i!=n-1) st=nums[i+1];
            }
        }
        return vec;
    }
};