class Solution {
public:
    unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};

    bool isVowel(const string& word) {
        int m = word.size();
        return vowel.find(word[0]) != vowel.end() && vowel.find(word[m - 1]) != vowel.end();
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();

        // Step 1: Build a prefix sum array
        vector<int> prefixSum(n + 1, 0); // prefixSum[i] stores count of vowel strings from index 0 to i-1
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + (isVowel(words[i]) ? 1 : 0);
        }

        // Step 2: Process each query
        vector<int> result;
        for (auto& query : queries) {
            int l = query[0];
            int r = query[1];
            result.push_back(prefixSum[r + 1] - prefixSum[l]);
        }

        return result;
    }
};
