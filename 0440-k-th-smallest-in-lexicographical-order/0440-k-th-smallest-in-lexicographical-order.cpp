class Solution {
public:
    // Helper function to count steps between two numbers
    int countSteps(long curr, long n) {
        long steps = 0;
        long first = curr, last = curr;
        while (first <= n) {
            steps += min(last, (long)n) - first + 1;
            first *= 10;
            last = last * 10 + 9;
        }
        return steps;
    }
    
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--; // since we start from 1, we need to adjust k

        while (k > 0) {
            int steps = countSteps(curr, n);
            if (steps <= k) {
                // Skip the current subtree
                curr++;
                k -= steps;
            } else {
                // Go down to the next level in the current subtree
                curr *= 10;
                k--;
            }
        }
        
        return curr;
    }
};
