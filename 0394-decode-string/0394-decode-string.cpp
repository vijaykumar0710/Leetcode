class Solution {
public:
    string decodeString(string s) {
   stack<string> st;
   string currentString = "";
    int k = 0;

    for (char ch : s) {
        if (isdigit(ch)) {
            k = k * 10 + (ch - '0');
        } else if (ch == '[') {
            st.push(currentString);
            st.push(to_string(k));
            currentString = "";
            k = 0;
        } else if (ch == ']') {
            int repeatTimes = stoi(st.top());
            st.pop();
            string previousString = st.top();
            st.pop();
            string repeatedString = "";
            for (int i = 0; i < repeatTimes; ++i) {
                repeatedString += currentString;
            }
            currentString = previousString + repeatedString;
        } else {
            currentString += ch;
        }
    }

    return currentString;
    }
};