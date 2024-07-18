class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1;
        unordered_set<int> st2;
        vector<int> result;
        for(int i=0;i<nums1.size();i++){
            st1.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            st2.insert(nums2[i]);
        }
        for(auto &ele:st1){
            if(st2.find(ele)!=st2.end()){
             result.push_back(ele);
            }
        }
        return result;
    }
};