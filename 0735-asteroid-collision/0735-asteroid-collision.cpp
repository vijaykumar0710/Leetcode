class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
       stack<int> st;
       for(int &a:asteroids){
        while(!st.empty() && a<0 && st.top()>0){
            int sum=a+st.top();
            if(sum<0){
                st.pop();
            }else if(sum>0){
             a=0;
            }else{
                st.pop();
                a=0;
            }
         }
         if(a!=0){
            st.push(a);
         }
       }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};