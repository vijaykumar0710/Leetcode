class Solution {
public:
    bool isPrime(long long n) {
        if(n<=1) return false; 
       for(long long factor=2;factor*factor<=n;factor++){
        if(n%factor==0) return false;
       }
       return true;
    }

    long long sumOfLargestPrimes(string s) {
        set<long long> st;

        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                string str = s.substr(i, j - i + 1);
                if (str[0] == '0') continue;
                long long num = stoll(str);
                if (isPrime(num)) {
                    st.insert(num);
                }
            }
        }

        vector<long long> primes(st.begin(), st.end());
        sort(primes.rbegin(), primes.rend());

        long long res = 0;
        for (int i = 0; i < min(3, (int)primes.size()); i++) {
            res += primes[i];
        }
        return res;
    }
};
