class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n=dominoes.size();
        int cnt=0;
        for(int i=0;i<n;i++){
           int a=dominoes[i][0];
           int b=dominoes[i][1];
           for(int j=i+1;j<n;j++){
            int c=dominoes[j][0];
            int d=dominoes[j][1];
            if((a == c and b == d) or (a == d and b == c))
              cnt++;
           }
        }
        return cnt;
    }
};