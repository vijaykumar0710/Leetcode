class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(nums[j]==-temp[i]) return temp[i];
            }
        }
        return -1;
    }
};