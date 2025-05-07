class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n=s.length();
        vector<char>vec(n);
        string res;
        for(int i=0;i<n;i++){
            vec[indices[i]]=s[i];
        }
        for(auto x:vec)
           res.push_back(x);
        return res;
    }
};