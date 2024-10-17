class Solution {
public:
    typedef pair<int, int> p;
    
    int maximumSwap(int num) {
        string st = to_string(num);
        int n = st.size();
        vector<int> last(10, -1);  // To store the last occurrence of each digit
        
        // Record the last occurrence of each digit
        for (int i = 0; i < n; i++) {
            last[st[i] - '0'] = i;
        }
        
        // Traverse through each digit and try to find a larger digit in the remaining part
        for (int i = 0; i < n; i++) {
            for (int d = 9; d > st[i] - '0'; d--) {
                if (st[i] > d && i<last[d]) {
                    // If a larger digit exists later, swap and return
                    swap(st[i], st[last[d]]);
                    return stoi(st);  // Convert the modified string back to an integer
                }
            }
        }
        
        return num;  // If no swap is done, return the original number
    }
};
