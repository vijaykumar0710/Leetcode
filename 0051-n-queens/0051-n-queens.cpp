class Solution {
public:
unordered_set<int>cols,dia,antidia;
void solve(int n,int row,vector<string>&curr,vector<vector<string>>&ans){
    if(row>=curr.size()){
        ans.push_back(curr);
        return;
    }
    for(int col=0;col<n;col++){
        int diag=row+col;
        int antidiag=row-col;
        if(cols.find(col)==cols.end() && dia.find(diag)==dia.end() && antidia.find(antidiag)==antidia.end()){
            curr[row][col]='Q';
            cols.insert(col);
            dia.insert(row+col);
            antidia.insert(row-col);

            solve(n,row+1,curr,ans);

             curr[row][col]='.';
            cols.erase(col);
            dia.erase(row+col);
            antidia.erase(row-col);
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        if(n==0) return {};
        vector<vector<string>>ans;
        vector<string> curr(n, string(n, '.')); 
        solve(n,0,curr,ans);
        return ans;
    }
};