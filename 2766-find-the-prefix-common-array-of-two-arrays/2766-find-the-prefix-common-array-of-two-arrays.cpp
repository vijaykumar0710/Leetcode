class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n =A.size();
        vector<int>res(n);
        for(int i=0;i<n;i++){
            int cnt=0;
          for(int j=i;j>=0;j--){
            for(int k=i;k>=0;k--){
                if(A[j]==B[k])cnt++;
            }
          }
          res[i]=cnt;
        }
        return res;
    }
};