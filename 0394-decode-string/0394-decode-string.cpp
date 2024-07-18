class Solution {
public:
    string decodeString(string s) {
    stack<int> counts;
    stack<string> resultStack;
    string result = "";
    int i = 0;

    while (i < s.size()) {
        if (isdigit(s[i])) {
            int count = 0;
            while (isdigit(s[i])) {
                count = count * 10 + (s[i] - '0');
                i++;
            }
            counts.push(count);
        } else if (s[i] == '[') {
            resultStack.push(result);
            result = "";
            i++;
        } else if (s[i] == ']') {
            std::string temp = resultStack.top();
            resultStack.pop();
            int count = counts.top();
            counts.pop();
            for (int j = 0; j < count; j++) {
                temp += result;
            }
            result = temp;
            i++;
        } else {
            result += s[i];
            i++;
        }
    }

    return result;
    }
};