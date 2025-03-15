class Solution {
public:
bool isValid(vector<int>& nums,int mid,int k,int n){
    int i=0,cnt=0;
    while(i<n){
        if(nums[i]<=mid){
            cnt++;
            i+=2;
        }else{
            i++;
        }
    }
    return cnt>=k;
}
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int l=*min_element(begin(nums),end(nums));
        int r=*max_element(begin(nums),end(nums));
        int res=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(nums,mid,k,n)){
            res=mid;
            r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return res;
    }
};