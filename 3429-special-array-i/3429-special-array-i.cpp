class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        bool flag=true;
        if(nums[0]%2!=0){
            flag=false;
        }
        if(flag==true){
            for(int i=1;i<n;i++){
                if(i%2!=0 && nums[i]%2==0) return false;       
            }
        }else{
            for(int i=1;i<n;i++){
               if(i%2!=0 && nums[i]%2==0) return false;
            }
        }
        return true;
    }
};