class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
      int n=nums.size();
      vector<int>vec1,vec2;
      for(auto &num:nums){
       if(num>0) vec1.push_back(num);
       if(num<0) vec2.push_back(num);
      }
      vector<int>res;
      for(int i=0;i<vec1.size();i++){
          res.push_back(vec1[i]);
          res.push_back(vec2[i]); 
      }
      return res;
    }
};