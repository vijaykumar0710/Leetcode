class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
 vector<vector<bool>> pal(n, vector<bool>(n, false));
 int cnt=0;
for (int r = 0; r < n; r++) {
    for (int l = r; l >= 0; l--) {
        if (s[l] == s[r] && (r - l < 2 || pal[l+1][r-1])) {
            pal[l][r] = true;
            cnt++;
        }
    }
}
   return cnt;
    }
};