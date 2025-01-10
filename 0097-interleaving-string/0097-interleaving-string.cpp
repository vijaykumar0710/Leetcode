class Solution {
public:
int m,n,p;
int t[101][101];
bool solver(string &s1,string &s2,string &s3,int i,int j){
    if(i==m && j==n && (i+j)==p)return true;
    if(t[i][j]!=-1)return t[i][j];
    if(i<m && (i+j)<p && s3[i+j]==s1[i]){
        if(solver(s1,s2,s3,i+1,j)){
           return t[i][j]=true;
        }
    }
    if(j<n && (i+j)<p && s3[i+j]==s2[j]){
        if(solver(s1,s2,s3,i,j+1)){
           return t[i][j]=true;
        }
    }
    return t[i][j]=false;
}
    bool isInterleave(string s1, string s2, string s3) {
        m=s1.size();
        n=s2.size();
        p=s3.size();
        if(m+n!=p) return false;
        memset(t,-1,sizeof(t));
        return solver(s1,s2,s3,0,0);
    }
};