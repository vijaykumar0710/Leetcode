class Solution {
public:
    int similarPairs(vector<string>& words) {
       vector<string>vec;
       set<char>st;
      for(auto &word:words){
        for(auto x:word){
            st.insert(x);
        }
        string y="";
        for(auto &x:st){
            y+=x;
        }
        vec.push_back(y);
        st.clear();
      }
     int cnt=0;
     for(int i=0;i<vec.size();i++){
        for(int j=i+1;j<vec.size();j++){
            if(vec[i]==vec[j]){
                cnt++;
            }
        }
     }
     return cnt;
    }
};