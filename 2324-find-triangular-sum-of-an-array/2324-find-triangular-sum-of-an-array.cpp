class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        for(auto &num:nums){
            temp.push_back(num);
        }
        while(n>=1){
            vector<int>vec;
            for(int i=0;i<n-1;i++){
                vec.push_back((temp[i]+temp[i+1])%10);
            }
            n--;
            temp.clear();
             for(auto &num:vec){
            temp.push_back(num);
           }
        }
        return temp[0];
    }
};