class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        if(n<=8) return n;
        if(n<=16){ 
              return 8+2*(n-8);
        }
        if(n<=24){
             return 8+2*8+3*(n-16);
        }
        if(n>=24){
          return 8+2*8+3*8+4*(n-24);
        }
        return 0;
    }
};