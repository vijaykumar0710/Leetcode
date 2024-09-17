class Solution {
public:
    string convertToTitle(int columnNumber) {
        string st;
        while(columnNumber>0){
            columnNumber--;
            int rem=columnNumber%26;
            st+=char(rem+'A');
            columnNumber=columnNumber/26;
        }
      reverse(st.begin(),st.end());
      return st;
    }
};