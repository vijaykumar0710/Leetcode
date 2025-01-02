class Solution {
public:
  int totalMatches=0; 
    int numberOfMatches(int n) {
        totalMatches+=n/2;
       if(n>1)numberOfMatches(n-(n/2));
       return totalMatches;
    }
};