class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        stack<int>mono;
        for(int i=0;i<n;i++){
           if(mono.empty() || nums[i]<=nums[mono.top()]){
            mono.push(i);
           }
        }
        int max_ramp=0;
        int j=n-1;
        while(j>=0){
           while(!mono.empty() && nums[j]>=nums[mono.top()]){
            int i=mono.top();
            max_ramp=max(max_ramp,(j-i));
            mono.pop();
           }
            j--;
        }
        return max_ramp;
    }
};