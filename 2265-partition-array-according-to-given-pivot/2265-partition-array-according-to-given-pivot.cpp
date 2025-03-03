class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>res;
        for(auto &num:nums){
            if(num<pivot)
               res.push_back(num);
        }
        for(auto &num:nums){
            if(num==pivot)
               res.push_back(num);
        }
         for(auto &num:nums){
            if(num>pivot)
               res.push_back(num);
        }
        return res;
    }
};