class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reverse=0;
        for(int i=0;i<32;i++){
            reverse|=(n&1)<<(31-i);
            n>>=1;
        }
        return reverse;
    }
};