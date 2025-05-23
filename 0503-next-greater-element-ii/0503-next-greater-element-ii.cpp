class Solution {
public:
vector<int>solve(vector<int>&v){
stack<int>st;
int n=v.size();
vector<int>temp(n);
 for(int i=n-1;i>=0;i--){
    while(!st.empty() && v[st.top()]<=v[i])
      st.pop();
      if(!st.empty()){
        temp[i]=(v[st.top()]);
      }else temp[i]=-1;
      st.push(i);
 }
 vector<int>res(temp.begin(),temp.begin()+(n/2));
 return res;
}
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>v=nums;
        for(auto &num:nums){
            v.push_back(num);
        }
        return solve(v);
    }
};