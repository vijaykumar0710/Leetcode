class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp;
        for(auto &ch:s){
            mp[ch]++;
        }
        vector<int>vec;
        for(auto [_,freq]:mp){
            vec.push_back(freq);
        }
        sort(begin(vec),end(vec));
        unordered_set<int>st;
        int cnt=0;
        for(int i=0;i<vec.size();i++){
            if(st.find(vec[i])!=st.end()){
                while(st.find(vec[i])!=st.end()){
                    vec[i]--;
                    cnt++;
                }
              if(vec[i]!=0){
                st.insert(vec[i]);
              }
            }else{
                st.insert(vec[i]);
            }
        }
        return cnt;
    }
};