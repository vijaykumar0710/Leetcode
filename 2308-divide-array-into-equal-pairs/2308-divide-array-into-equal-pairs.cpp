class Solution {
public:
    bool divideArray(vector<int>& nums) {
        bitset<501> parity;
        for (int x : nums) {
            parity.flip(x);
        }
        return parity.count() == 0;
    }
};