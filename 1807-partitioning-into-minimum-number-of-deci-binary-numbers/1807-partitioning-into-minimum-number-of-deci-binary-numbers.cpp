class Solution {
public:
    int minPartitions(string n) {
       int size=n.length();
       int deci_binary=0;
       for(int i=0;i<size;i++){
          deci_binary=max(deci_binary,n[i]-'0'); 
       }
       return deci_binary;
    }
};