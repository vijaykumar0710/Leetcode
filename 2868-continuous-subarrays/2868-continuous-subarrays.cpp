class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        int i = 0, j = 0;
        
        deque<int> maxDeque; // Monotonically decreasing deque (stores indices)
        deque<int> minDeque; // Monotonically increasing deque (stores indices)
        
        while (j < n) {
            // Maintain maxDeque
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[j]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(j);

            // Maintain minDeque
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[j]) {
                minDeque.pop_back();
            }
            minDeque.push_back(j);

            // Check if the window is valid
            while (nums[maxDeque.front()] - nums[minDeque.front()] > 2) {
                // Shrink the window from the left
                if (maxDeque.front() == i) maxDeque.pop_front();
                if (minDeque.front() == i) minDeque.pop_front();
                i++;
            }

            // Count subarrays ending at `j`
            cnt += (j - i + 1);
            j++; // Expand the window
        }

        return cnt;
    }
};
