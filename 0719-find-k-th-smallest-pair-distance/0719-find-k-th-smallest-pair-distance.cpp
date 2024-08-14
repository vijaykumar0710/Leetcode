class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>res;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){ 
           res.push_back(nums[j]-nums[i]);
            }
        }
       nth_element(begin(res),begin(res)+(k-1),end(res));
        return res[k-1];
    }
};