class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        stack<int>st;
        unordered_map<int,int>mp;
        vector<int>vec(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums2[st.top()]<=nums2[i])
                st.pop();
           if(!st.empty())
           vec[i]=nums2[st.top()];
            st.push(i);
            mp[nums2[i]]=i;
        } 
        vector<int>res;
        for(int i=0;i<nums1.size();i++){
            int idx=mp[nums1[i]];
            res.push_back(vec[idx]);
        }
        return res;
    }
};