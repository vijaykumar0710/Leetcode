class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.size();
        int m=part.length();
        string res="";
        for(int i=0;i<n;i++){
            res+=s[i];
            if(res.size()>=m && res.substr(res.size()-m)==part){
                    res.erase(res.size()-m,m);
            }
        }
        return res;
    }
};