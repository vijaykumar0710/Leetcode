class Solution {
public:
const int MOD=1e9+7;
    int sumSubarrayMins(vector<int>& heights) {
        int n=heights.size();
     int maxArea=0;
     stack<int>st;
     vector<int>pse(n),nse(n);
     for(int i=0;i<n;i++){
        while(!st.empty() && heights[st.top()]>heights[i]){ 
               st.pop();
        }
          pse[i]=st.empty()?-1:st.top();
        st.push(i);
       } 
       stack<int>st2;
       for(int i=n-1;i>=0;i--){
        while(!st2.empty() && heights[st2.top()]>=heights[i]){ 
               st2.pop();
        }
          nse[i]=st2.empty()?n:st2.top();
          st2.push(i);
       }  
       long long res=0;
       for(int i=0;i<n;i++){
        long long left=i-pse[i];
        long long right=nse[i]-i;
        res = (res + (heights[i] * left % MOD) * right % MOD) % MOD;
       }
       return res;
    }
};