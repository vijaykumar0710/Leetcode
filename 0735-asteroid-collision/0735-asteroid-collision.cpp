class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            int num=asteroids[i];
            if(num>0) st.push(num);
            else{
             while(!st.empty() && st.top()>0 && st.top()<abs(num)){ 
               st.pop();
              }
             if(!st.empty() && st.top()>0 && st.top()==abs(num)) st.pop();
             else if(st.empty() || st.top()<0) st.push(num);
        }
        }
         vector<int>res;
          while(!st.empty()){
            res.push_back(st.top());
            st.pop();
          }
          reverse(res.begin(),res.end());
          return res;
    }
};

 