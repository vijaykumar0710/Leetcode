class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>expectedNum;
       unordered_set<int>st;
       for(auto &num:nums){
        st.insert(num);
       }
       for(auto &num:st){
        expectedNum.push_back(num);
       }
       sort(begin(expectedNum),end(expectedNum));
       int k=expectedNum.size();
       for(int i=0;i<k;i++){
        nums[i]=expectedNum[i];
       }
       return k;
    }
};