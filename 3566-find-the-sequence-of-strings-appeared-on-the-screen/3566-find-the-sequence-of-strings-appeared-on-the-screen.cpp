class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> result;
        string current = "";  // Start with an empty screen
        
        for (char c : target) {
            // Step 1: Press Key 1 to append 'a'
            current += 'a';
            result.push_back(current);  // Add the string after Key 1 press
            
            // Step 2: Use Key 2 to reach the target character if necessary
            while (current.back() != c) {
                current.back() = (current.back() == 'z') ? 'a' : current.back() + 1;
                result.push_back(current);  // Add the string after each Key 2 press
            }
        }
        
        return result;
    }
};
