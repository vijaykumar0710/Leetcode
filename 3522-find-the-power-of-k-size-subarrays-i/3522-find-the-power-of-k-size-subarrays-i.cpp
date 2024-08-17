class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n - k + 1, -1);
        
        for (int i = 0; i <= n - k; i++) {
            bool isConseSort = true;
            
            for (int j = i; j < i + k-1 ; j++) {
                if (nums[j] + 1 != nums[j + 1]) {
                    isConseSort = false;
                    break;
                }
            }
            
            if (isConseSort) {
                res[i] = nums[i + k - 1];
            }
        }
        
        return res;
    }
};