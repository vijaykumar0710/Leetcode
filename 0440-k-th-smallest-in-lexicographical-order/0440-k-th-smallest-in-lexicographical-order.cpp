class Solution {
public:
    // Helper function to count steps between two numbers
    int Count(long curr, long next,int n) {
        int countNum = 0;
    
        while (curr <= n) {
            countNum += (next-curr);
            curr *= 10;
            next *=10;
            next =min(next,long(n+1));
        }
        return countNum;
    }
    
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--; // since we start from 1, we need to adjust k

        while (k > 0) {
            int count = Count(curr, curr+1,n);
            if (count <= k) {
                // Skip the current subtree
                curr++;
                k -= count;
            } else {
                // Go down to the next level in the current subtree
                curr *= 10;
                k--;
            }
        }
        return curr;
    }
};