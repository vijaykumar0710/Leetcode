class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec;
        for(int i=0;i<numRows;i++){
            vector<int>a(i+1);
            vec.push_back(a);
        }
        for(int i=0;i<numRows;i++){
            for(int j=0;j<=i;j++){
                if(j==0 || i==j){
                    vec[i][j]=1;
                }
                else{
                    vec[i][j]=vec[i-1][j-1]+vec[i-1][j];
                }
            }
        }
        return vec;
    }
};