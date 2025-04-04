class Solution {
public:
unordered_set<int>cols,dia,antidia;
void solve(int n,int row,int &cnt,vector<string>&curr){
    if(row>=n){
        cnt++;
        return;
    }
    for(int col=0;col<n;col++){
        if(cols.find(col)==cols.end() && dia.find(row+col)==dia.end() && antidia.find(row-col)==antidia.end()){
            curr[row][col]='Q';
            cols.insert(col);
            dia.insert(row+col);
            antidia.insert(row-col);

            solve(n,row+1,cnt,curr);

            curr[row][col]='.';
            cols.erase(col);
            dia.erase(row+col);
            antidia.erase(row-col);
        }
    }
}
    int totalNQueens(int n) {
        if(n==0) return {};
        vector<string>curr(n,string(n,'.'));
        int cnt=0;
        solve(n,0,cnt,curr);
        return cnt;
    }
};