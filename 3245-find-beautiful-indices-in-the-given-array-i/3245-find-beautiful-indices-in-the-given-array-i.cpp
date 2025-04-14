class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> posA = kmpSearch(s, a);
        vector<int> posB = kmpSearch(s, b);
        vector<int> res;

        int i = 0, j = 0;
        while (i < posA.size()) {
            while (j < posB.size() && posB[j] < posA[i] - k) j++;
            int temp = j;
            while (temp < posB.size() && posB[temp] <= posA[i] + k) {
                res.push_back(posA[i]);
                break;
            }
            i++;
        }

        sort(res.begin(), res.end());
        return res;
    }

    // KMP prefix function
    vector<int> kmpSearch(string& text, string& pattern) {
        int n = text.size(), m = pattern.size();
        vector<int> lps(m, 0), res;
        int len = 0, i = 1;

        // Build LPS array
        while (i < m) {
            if (pattern[i] == pattern[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        // Search using LPS
        i = 0;
        int j = 0;
        while (i < n) {
            if (text[i] == pattern[j]) {
                i++; j++;
                if (j == m) {
                    res.push_back(i - j);
                    j = lps[j - 1];
                }
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }

        return res;
    }
};
