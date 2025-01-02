class Solution {
public:
    int xorOperation(int n, int start) {
        int bitwise_XOR=0;
        for(int i=0;i<n;i++){
           bitwise_XOR^=(start+2*i);
        }
        return bitwise_XOR;
    }
};