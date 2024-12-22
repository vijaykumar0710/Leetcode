class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto &num:nums){
             st.insert(num);
        }
        int maxi=0;
       for(auto &num:nums){
        int cnt=0;
             if(st.find(num-1)==st.end()){
                while(st.find(num)!=st.end()){
                    cnt++;
                    num++;
                }
             }
             maxi=max(maxi,cnt);
        }
        return maxi;
    }
};