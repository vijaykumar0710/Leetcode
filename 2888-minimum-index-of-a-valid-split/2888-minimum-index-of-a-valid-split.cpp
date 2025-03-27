class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
       unordered_map<int,int>mp;
       int majority_element=-1;
       int freq=0;
       for(auto num:nums){
        mp[num]++;
       }
       for(auto [ele,fre]:mp){
        if(2*fre>n){
           majority_element=ele;
           freq=fre;
           break;
        }
       }
       int f1=0;
       for(int i=0;i<n;i++){
           if(nums[i]==majority_element){
            f1++;
           }
             if(f1*2>(i+1) && 2*(freq-f1)>(n-i-1)){
                return i;
            }
       }
       return -1;
    }
};