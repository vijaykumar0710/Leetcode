class Solution {
public:
    vector<string> stringMatching(vector<string> &words) {
        int size = words.size();
        set<string> result; // Use a set to store unique subsequences

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if(i==j) continue;
                if(words[j].find(words[i])!=string::npos){
                    result.insert(words[i]);
                }
            }
        }
        return vector<string>(result.begin(), result.end()); // Convert set to vector
    }
};