class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int vec[n];
        int prev=0;
        for(int i=0;i<n;i++){
            vec[i]=prev;
            prev=prev+nums[i];
        }
        int arr[n];
        int next=0;
        for(int i=n-1;i>=0;i--){
             arr[i]=next;
             next=next+nums[i];
        }
        for(int i=0;i<n;i++){
            nums[i]=abs(vec[i]-arr[i]);
        }
        return nums;
    }
};