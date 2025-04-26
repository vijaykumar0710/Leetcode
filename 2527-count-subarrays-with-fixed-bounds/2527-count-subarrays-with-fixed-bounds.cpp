class Solution {
public:
    void suffix(vector<int>& nums, vector<int>& vec, int minK, int maxK) {
        int n = nums.size();
        if (nums[n - 1] >= minK && nums[n - 1] <= maxK) {
            vec[n - 1] = 1;
        } else {
            vec[n - 1] = 0;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] >= minK && nums[i] <= maxK) {
                vec[i] = 1 + vec[i + 1];
            } else {
                vec[i] = 0;
            }
        }
    }

    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        vector<int> vec(n, 0);
        suffix(nums, vec, minK, maxK);

        int i = 0, j = 0;
        long long cnt = 0;
        map<int, int> mp;
        
        while (j < n) {
            // If the current number is outside the range [minK, maxK], move `j` and reset `i`
            if (nums[j] < minK || nums[j] > maxK) {
                j++;
                i = j;  // Reset the sliding window start to the current position
                mp.clear();  // Clear the map to start fresh
            } else {
                // Count valid subarrays when both minK and maxK are present in the window
                mp[nums[j]]++;
                
                // If both minK and maxK are in the current window, check for valid subarrays
                while (!mp.empty() && mp.count(minK) && mp.count(maxK)) {
                    if (j + 1 < n) {
                        cnt += (1 + vec[j + 1]);
                    } else {
                        cnt++;
                    }
                    
                    // Slide the window by removing the element at `i`
                    mp[nums[i]]--;
                    if (mp[nums[i]] == 0) {
                        mp.erase(nums[i]);
                    }
                    i++;  // Move `i` to shrink the window from the left
                }
                j++;  // Expand the window by moving `j`
            }
        }

        return cnt;
    }
};
