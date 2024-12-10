class Solution {
public:
    int minPartitions(string n) {
       int size=n.length();
       int deci_binary=0;
       for(int i=0;i<size;i++){
         int num=n[i]-'0';
          deci_binary=max(deci_binary,num); 
       }
       return deci_binary;
    }
};