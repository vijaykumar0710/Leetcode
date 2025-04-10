class Solution {
public:
    using ll = long long;
    ll dp[17][2]; // Memoization table

    ll solve(int idx, int tight, string &num, string &s, int limit, int n){
        if(idx == n) return 1; // Base case: valid number found
        if(dp[idx][tight] != -1) return dp[idx][tight]; // Return memoized result

        int lb=0;
        int ub = tight ? min(limit, num[idx]-'0') : limit; // Upper bound based on tight condition

        // Handle suffix constraint
        int suffix_start_ind = n-s.size();
        if(suffix_start_ind<=idx){
            lb = s[idx-suffix_start_ind]-'0';
            ub = min(ub, s[idx-suffix_start_ind]-'0');
        }

        ll ans=0;
        for(int i=lb;i<=ub;i++){
            // Recursive call for next digit
            ans += solve(idx+1, tight&&(i==num[idx]-'0'), num, s, limit, n);
        }

        return dp[idx][tight] = ans; // Memoize and return result
    }

    ll numberOfPowerfulInt(ll start, ll finish, int limit, string s) {
        string r = to_string(finish);
        string l = to_string(start-1);
        int n = r.size();
        int m = l.size();
        
        ll a=0, b=0;
        memset(dp, -1, sizeof(dp));
        if(s.size()<=n){
            a = solve(0, 1, r, s, limit, n); // Count for upper bound
        }
        
        memset(dp, -1, sizeof(dp));
        if(s.size()<=m){
            b = solve(0, 1, l, s, limit, m); // Count for lower bound - 1
        }
        
        return a-b; // Return difference
    }
};