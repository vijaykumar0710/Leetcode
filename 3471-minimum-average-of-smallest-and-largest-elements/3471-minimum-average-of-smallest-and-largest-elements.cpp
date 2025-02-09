class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        double minAvg=INT_MAX;
        int i=0,j=n-1;
        while(i<j){
            double avg=(nums[i]+nums[j])/2.0;
            if(minAvg>avg) minAvg=avg;
            i++;
            j--;
        }
        return minAvg;
    }
};