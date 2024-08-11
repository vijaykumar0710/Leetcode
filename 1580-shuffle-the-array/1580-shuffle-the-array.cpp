class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> vec1;
        vector<int>vec2;
        for(int i=0;i<n;i++){
          vec1.push_back(nums[i]);
        }
         for(int j=n;j<2*n;j++){ 
          vec2.push_back(nums[j]); 
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            res.push_back(vec1[i]);
            res.push_back(vec2[i]); 
        }
        return res;
    }
};