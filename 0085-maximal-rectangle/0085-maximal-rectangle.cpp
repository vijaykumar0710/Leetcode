class Solution {
public:
int MAH(vector<int>&heights,int n){
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;
        vector<int>vec(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(matrix[i][j]=='0')
               vec[j]=0;
                else vec[j]+=1;
            }
            ans=max(ans,MAH(vec,n));
        }
        return ans;
    }
};