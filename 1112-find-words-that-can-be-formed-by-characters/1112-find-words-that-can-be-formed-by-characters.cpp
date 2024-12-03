class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> charFreq;
        for (char ch : chars) {
            charFreq[ch]++;
        }

        int totalLength = 0;
        for (string& word : words) {
            unordered_map<char, int> tempFreq = charFreq;
            bool canForm = true;
            
            for (char ch : word) {
                if (tempFreq[ch] > 0) {
                    tempFreq[ch]--;
                } else {
                    canForm = false;
                    break;
                }
            }

            if (canForm) {
                totalLength += word.size();
            }
        }

        return totalLength;
    }
};
