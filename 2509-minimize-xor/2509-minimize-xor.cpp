class Solution {
public:
bool isSet(int &x,int bit){
    return x & (1<<bit);
}
bool setBit(int &x,int bit){
    return x |= (1<<bit);
}
bool UnsetBit(int &x,int bit){
     return x &= ~(1<<bit);
}
    int minimizeXor(int num1, int num2) {
       int x=num1;
       int requiredSetBitCount=__builtin_popcount(num2);
       int currentSetBitCount=__builtin_popcount(x);
       int bit=0;
       if(currentSetBitCount<requiredSetBitCount){
           while(currentSetBitCount<requiredSetBitCount){
               if(!isSet(x,bit)){
                   setBit(x,bit);
                   currentSetBitCount++;
               }
               bit++;
           }
       }else if(currentSetBitCount>requiredSetBitCount){
             while(currentSetBitCount>requiredSetBitCount){
                if(isSet(x,bit)){
                    UnsetBit(x,bit);
                    currentSetBitCount--;
                }
                bit++;
             }
         }
         return x;
    }
};