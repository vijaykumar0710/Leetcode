class Solution {
public:
    int countPoints(string rings) {
        int n=rings.size();
        vector<set<char>>vec(10);
        for(int i=0;i<n;i+=2){
            int x=rings[i+1]-'0';
            vec[x].insert(rings[i]);
        }
      int cnt=0;
      for(auto &st:vec){
         if(st.size()==3) cnt++;
      }
        return cnt;
    }
};