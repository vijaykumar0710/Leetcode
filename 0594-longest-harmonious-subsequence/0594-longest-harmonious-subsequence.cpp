class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int>mp;
        unordered_set<int> st;
        vector<int>vec;
        for(auto &num:nums){
            st.insert(num);
            mp[num]++;
        }
       for(auto &num:st){
         vec.push_back(num);
       }
       sort(vec.begin(),vec.end());
       int result=0;
       for(int i=0;i<vec.size()-1;i++){
        if(vec[i+1]-vec[i]==1){
        int num1=mp[vec[i]];
        int num2=mp[vec[i+1]];
        result=max(result,num1+num2);
         }
       }
       return result;
    }
};