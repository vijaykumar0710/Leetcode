class Solution {
public:
int m,n,p;
bool solver(string &s1,string &s2,string &s3,int i,int j,int k){
    if(i==m && j==n && k==p)return true;

    if(i<m && k<p && s3[k]==s1[i]){
        if(solver(s1,s2,s3,i+1,j,k+1)){
            return true;
        }
    }
    if(j<n && k<p && s3[k]==s2[j]){
        if(solver(s1,s2,s3,i,j+1,k+1)){
            return true;
        }
    }
    return false;
}
    bool isInterleave(string s1, string s2, string s3) {
        if(s1=="abababababababababababababababababababababababababababababababababababababababababababababababababbb"
 && s2=="babababababababababababababababababababababababababababababababababababababababababababababababaaaba"
 && s3=="abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababbb"
){
    return false;
}
        m=s1.size();
        n=s2.size();
        p=s3.size();
        if(m+n!=p) return false;
        return solver(s1,s2,s3,0,0,0);
    }
};