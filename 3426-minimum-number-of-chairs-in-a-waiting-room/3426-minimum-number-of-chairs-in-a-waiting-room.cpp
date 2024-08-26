class Solution {
public:
    int minimumChairs(string s) {
     int c = 0;
    int m = 0;

    for (char e: s) {
        if (e == 'E') {
            c++;
        } else if (e == 'L') {
            c--;
        }
        if (c > m) {
            m = c;
        }
    }

    return m;
    }
};