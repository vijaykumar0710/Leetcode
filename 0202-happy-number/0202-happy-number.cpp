class Solution {
public:
    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
        
        // Use two pointers, fast moves twice as fast as slow
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);          // Move slow pointer one step
            fast = getNext(getNext(fast)); // Move fast pointer two steps
        }
        
        return fast == 1; // If fast pointer reaches 1, n is a happy number
    }
};
