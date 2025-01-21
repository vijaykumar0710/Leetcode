class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority_element;
        int cnt=0;
        for(auto &num:nums){
            if(cnt==0){
                majority_element=num;
                cnt=1;
            }else{
                (majority_element==num)?cnt++:cnt--;
            }
        }
        return majority_element;
    }
};