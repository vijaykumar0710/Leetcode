class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.size();
        vector<int>vec,res(n,n);
        for(int i=0;i<n;i++){
            if(s[i]==c)vec.push_back(i);
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<vec.size();j++){
                res[i]=min(res[i],abs(i-vec[j]));
            }
         }
         return res;
    }
};