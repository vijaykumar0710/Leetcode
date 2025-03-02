class Solution {
public:
int t[501][501];
    int minDistance(string word1, string word2) {
         int m=word1.size();
        int n=word2.size();
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0)
                   t[i][j]=0;
            }
        }
       for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(word1[i-1]==word2[j-1])
                   t[i][j]=1+t[i-1][j-1];
                else
                   t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        return m+n-2*t[m][n];
    }
};