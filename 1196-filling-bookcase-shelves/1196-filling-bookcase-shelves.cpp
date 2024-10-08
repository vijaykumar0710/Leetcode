class Solution {
public:
int n;
int WIDTH;
int dp[1001][1001];
int solve(vector<vector<int>>& books,int i,int remainW,int maxHt){
    if(i>=n) return maxHt;
    if(dp[i][remainW]!=-1) return dp[i][remainW];
    int bookW=books[i][0];
    int bookH=books[i][1];

    int keep=INT_MAX;
    int skip=INT_MAX;
    if(bookW<=remainW){
     keep=solve(books,i+1,remainW-bookW,max(maxHt,bookH));   
    }
    skip=maxHt+solve(books,i+1,WIDTH-bookW,bookH);

    return dp[i][remainW]=min(keep,skip);
}
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp,-1,sizeof(dp));
        n=books.size();
        WIDTH=shelfWidth;
        int remainW=shelfWidth;
        return solve(books,0,remainW,0);
    }
};