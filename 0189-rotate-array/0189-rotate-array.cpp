class Solution {
public:
void reversepart(int i,int j,vector<int>& nums){
    while(i<=j){
        swap(nums[i],nums[j]);
        i++,j--;
    }
}
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n) k=k%n;
        reversepart(0,n-k-1,nums);
        reversepart(n-k,n-1,nums);
        reversepart(0,n-1,nums);
    }
};