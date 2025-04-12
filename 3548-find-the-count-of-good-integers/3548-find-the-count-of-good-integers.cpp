typedef long long ll;

class Solution {
public:
    int n, k;
    ll ans = 0;
    // precomputed factorials up to 10!
    ll fact[11];

    // Precompute factorials.
    void initFact() {
        fact[0] = 1;
        for (int i = 1; i <= 10; i++) {
            fact[i] = fact[i-1] * i;
        }
    }
    
    // Given frequencies f[0..9] (summing to n) that describe an n-digit number,
    // count the number of arrangements with no leading zero.
    ll countArrangements(const vector<int>& f) {
        ll total = fact[n];
        for (int d = 0; d < 10; d++) {
            total /= fact[f[d]];
        }
        ll leadingZero = 0;
        if(f[0] > 0) {
            // Count arrangements where first digit is zero.
            ll rem = fact[n-1];
            vector<int> f2 = f;
            f2[0]--;
            for (int d = 0; d < 10; d++) {
                rem /= fact[f2[d]];
            }
            leadingZero = rem;
        }
        return total - leadingZero;
    }
    
    // Check if there is at least one palindromic permutation (with no leading zero)
    // from the digit frequency multiset f that is divisible by k.
    bool hasValidPalDivisible(const vector<int>& f) {
        // For a multiset to be rearranged into a palindrome, at most one digit can have an odd count.
        int oddCount = 0;
        int oddDigit = -1;
        for (int d = 0; d < 10; d++) {
            if (f[d] & 1) {
                oddCount++;
                oddDigit = d;
            }
        }
        if(oddCount > 1) return false; // cannot rearrange into a palindrome
        
        string half = "";
        // Build half of the palindrome (each digit d appears f[d]/2 times).
        for (int d = 0; d < 10; d++) {
            half.append(f[d] / 2, char('0' + d));
        }
        
        // If n==1, the palindrome is just the single digit.
        if (n == 1) {
            // Only one digit is present and it must be nonzero.
            if (half.empty()) {
                // When n==1, f[d]==1 for some d.
                for (int d = 1; d < 10; d++) {
                    if(f[d] == 1) {
                        int num = d;
                        if(num % k == 0)
                            return true;
                    }
                }
                return false;
            }
        }
        
        // Generate distinct permutations of the half.
        sort(half.begin(), half.end());
        // Use a set to avoid duplicate half permutations (though next_permutation on a sorted string
        // will generate all unique arrangements if we use it properly).
        do {
            // For nontrivial half (i.e. when n > 1, half will be non-empty except the n==1 case)
            if (!half.empty() && half[0] == '0')
                continue; // would lead to a palindrome with a leading 0
            
            string rev = half;
            reverse(rev.begin(), rev.end());
            string pal;
            if (n % 2 == 0) {
                pal = half + rev;
            } else {
                // There must be exactly one digit with odd frequency.
                char mid = char('0' + oddDigit);
                // For odd numbers, also ensure that if half is empty (n==1), the mid digit is nonzero.
                if(half.empty() && mid == '0')
                    continue;
                pal = half + string(1, mid) + rev;
            }
            // Use stoll for conversion; n<=10 so the number fits in 64-bit.
            ll num = stoll(pal);
            if(num % k == 0) return true;
            
        } while(next_permutation(half.begin(), half.end()));
        return false;
    }
    
    // Recursively enumerate frequency vectors f for digits 0...9 summing to rem.
    void rec(int d, int rem, vector<int>& f) {
        // If we have assigned frequencies for digits 0..9
        if (d == 10) {
            if(rem != 0) return; // must sum to n
            // Ensure the multiset can produce an n-digit number (i.e. not all digits zero)
            if(f[0] == n) return;
            
            // Check if the digits can be rearranged to form a palindrome
            // and at least one such palindrome is divisible by k.
            if(hasValidPalDivisible(f)) {
                ans += countArrangements(f);
            }
            return;
        }
        
        // for digit d, choose frequency from 0 to rem.
        for (int cnt = 0; cnt <= rem; cnt++) {
            f[d] = cnt;
            rec(d + 1, rem - cnt, f);
        }
    }
    
    long long countGoodIntegers(int _n, int _k) {
        n = _n, k = _k;
        ans = 0;
        initFact();
        vector<int> f(10,0);
        rec(0, n, f);
        return ans;
    }
};
