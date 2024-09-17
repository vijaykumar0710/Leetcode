class Solution {
public:
    string convertToTitle(int columnNumber) {
        string st;
        
        while(columnNumber > 0) {
            int rem = (columnNumber - 1) % 26;  // Adjust by -1 to handle the 1-based index
            st += char(rem + 'A');  // 'A' starts at 65 in ASCII
            columnNumber = (columnNumber - 1) / 26;  // Adjust column number
        }
        
        reverse(st.begin(), st.end());
        return st;
    }
};
