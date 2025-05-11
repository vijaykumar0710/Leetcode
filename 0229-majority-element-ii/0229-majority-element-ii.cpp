class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt1=0,maj1=NULL;
        int cnt2=0,maj2=NULL;

        for(auto &num:nums){
            if(maj1==num) cnt1++;
            else if(maj2==num) cnt2++;
            else if(cnt1==0){
                maj1=num;
                cnt1=1;
            }else if(cnt2==0){
                maj2=num;
                cnt2=1;
            }else{
                cnt1--;
                cnt2--;
            }
        }

        vector<int>result;
        cnt1=0,cnt2=0;
        for(auto &num:nums){
            if(num==maj1) cnt1++;
            else if(num==maj2) cnt2++;
        }
        if(cnt1>floor(n/3))
           result.push_back(maj1);
       if(cnt2>floor(n/3))
           result.push_back(maj2); 

        return result;
    }
};