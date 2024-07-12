class Solution {
public:
string removeSubstr(string &s,string &matchStr){
    int i=0;
    for(int j=0;j<s.length();j++){
        s[i]=s[j];
        i++;
        if(i>=2 && s[i-2] == matchStr[0] && s[i-1]==matchStr[1]){
            i-=2;
        }
    }
    s.erase(begin(s)+i,end(s));
    return s;
}
    int maximumGain(string s, int x, int y) {
        int n=s.length();
        int score=0;

        string maxStr=(x>y)?"ab":"ba";
        string minStr=(x<y)?"ab":"ba";

        string temp_first=removeSubstr(s,maxStr);
        int L=temp_first.length();

        int charRemoved=(n-L);
        score+=(charRemoved/2)*max(x,y);

        string temp_second=removeSubstr(temp_first,minStr);
        charRemoved=L-temp_second.length();

        score+=(charRemoved/2)*min(x,y);

        return score;
    }
};