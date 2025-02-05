class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        string st1=s1;
        string st2=s2;
        sort(st1.begin(),st1.end());
        sort(st2.begin(),st2.end());
        if(st1!=st2) return false;
        int cnt=0;
        for(int i=0,j=0;i<s1.size(),j<s1.size();i++,j++){
            if(s1[i]!=s2[j])cnt++;
        }
         if(cnt>2) return false;
         return true;
    }
};