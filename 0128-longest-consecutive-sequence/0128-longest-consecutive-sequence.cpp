class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;
        set<int> st;
        for(auto &num:nums){
             st.insert(num);
        }
        vector<int>vec;
        for(auto &num:st){
            vec.push_back(num);
        }
        int maxi=0;
        int cnt=1;
        for(int i=1;i<vec.size();i++){
             if(vec[i]-vec[i-1]==1){
                cnt++;
             }else{
                maxi=max(maxi,cnt);
                cnt=1;
             }
        }
        maxi=max(maxi,cnt);
        return maxi;
    }
};