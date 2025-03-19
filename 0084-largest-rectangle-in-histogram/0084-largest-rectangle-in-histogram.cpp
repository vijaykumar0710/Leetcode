class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
     int n=heights.size();
     int maxArea=0;
     stack<int>st;
     vector<int>pse(n),nse(n);
     for(int i=0;i<n;i++){
        while(!st.empty() && heights[st.top()]>=heights[i])
               st.pop();
          pse[i]=st.empty()?-1:st.top();
        st.push(i);
       } 
       stack<int>st2;
       for(int i=n-1;i>=0;i--){
        while(!st2.empty() && heights[st2.top()]>=heights[i])
               st2.pop();
          nse[i]=st2.empty()?n:st2.top();
          st2.push(i);
       }  
       for(int i=0;i<n;i++){
        int area=(nse[i]-pse[i]-1)*heights[i];
        maxArea=max(maxArea,area);
       }
      return maxArea;
    }
};