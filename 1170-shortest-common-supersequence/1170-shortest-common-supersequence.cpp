class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.size();
        int n=str2.size();
        vector<vector<int>>t(m+1,vector<int>(n+1));
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0){
                    t[i][j]=i+j;
                }else if(str1[i-1]==str2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }else{
                    t[i][j]=1+min(t[i][j-1],t[i-1][j]);
                }
            }
        }
            string result="";
            int i=m,j=n;
            while(i>0 && j>0){
                if(str1[i-1]==str2[j-1]){
                    result+=str1[i-1];
                    i--;
                    j--;
                }else{
                    if(t[i-1][j]<t[i][j-1]){
                        result+=str1[i-1];
                        i--;
                    }else{
                        result+=str2[j-1];
                        j--;
                    }
                }
            }
        while(i>0){
            result+=str1[i-1];
            i--;
        }
         while(j>0){
            result+=str2[j-1];
            j--;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};