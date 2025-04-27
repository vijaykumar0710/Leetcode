class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;
        for(auto &num:nums){
            st.insert(num);
        }
        vector<int>vec;
        for(auto &num:st){
            vec.push_back(num);
        }
        sort(vec.begin(),vec.end(),greater<int>());
        if(vec.size()<3) return vec[0];
        return vec[2];
    }
};