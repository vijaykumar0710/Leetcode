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
            if (nums[j] < minK || nums[j] > maxK) {
                j++;
                i = j;  
                mp.clear();  
            } else {
                mp[nums[j]]++;
                
                while (!mp.empty() && mp.count(minK) && mp.count(maxK)) {
                    if (j + 1 < n) {
                        cnt += (1 + vec[j + 1]);
                    } else {
                        cnt++;
                    }
                    mp[nums[i]]--;
                    if (mp[nums[i]] == 0) {
                        mp.erase(nums[i]);
                    }
                    i++;  
                }
                j++;  
            }
        }

        return cnt;
    }
};
