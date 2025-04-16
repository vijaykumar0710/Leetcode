class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        int res=0;
       vector<int>vec;
       for(int i=0;i<n-1;i++){
        vec.push_back(nums[i]-nums[i+1]);
       }
       int cnt=1;
       vector<int>group;
       for(int i=1;i<vec.size();i++){
        if(vec[i]==vec[i-1]){
            cnt++;
        }else{
            group.push_back(cnt);
            cnt=1;
         }
       }
       group.push_back(cnt);
       for(auto &n:group){
        if(n>1){
            res+=(n*(n-1)/2);
        }
       }
       return res;
    }
};