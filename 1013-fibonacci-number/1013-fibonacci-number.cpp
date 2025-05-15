class Solution {
public:
const int M=1e9+7;
typedef vector<vector<long long>>Matrix;

Matrix matrixMulti(Matrix &A ,Matrix &B){
    Matrix temp(A.size(),vector<long long>(B[0].size(),0));
    for(int i=0;i<A.size();i++){
        for(int j=0;j<B[0].size();j++){
            for(int k=0;k<A[0].size();k++){
              temp[i][j]=(temp[i][j]+A[i][k]*B[k][j])%M;
            }
        }
    }
    return temp;
}

Matrix matrixExpo(Matrix &base,int Expo){
    if(Expo==0){
        Matrix identity(2,vector<long long>(2,0));
        for(int i=0;i<2;i++){
            identity[i][i]=1;
        }
        return identity;
    }
    Matrix half=matrixExpo(base,Expo/2);
    Matrix ans=matrixMulti(half,half);
    if(Expo%2==1){
        ans=matrixMulti(ans,base);
    }
    return ans;
}

    int fib(int n) {
        if(n==0) return 0;
       Matrix T={{1,1},{1,0}};
       Matrix mat={{1},{0}}; // base case matrix

       Matrix Tn=matrixExpo(T,n-1);
       Matrix result=matrixMulti(Tn,mat);

       return result[0][0];
    }
};