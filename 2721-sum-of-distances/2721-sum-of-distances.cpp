class Solution {
public:
    void solve(vector<long long>& indices, vector<long long>& ans) {
        int n = indices.size();
        vector<long long> prefix(n);
        vector<long long> suffix(n);
        prefix[0] = indices[0];
        suffix[n - 1] = indices[n - 1];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + indices[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + indices[i];
        }
        ans[indices[0]] = suffix[1] - (n - 1) * indices[0];
        ans[indices[n - 1]] = (n - 1) * indices[n - 1] - prefix[n - 2];
        for (int i = 1; i < n - 1; i++) {
            long long left = i * indices[i] - prefix[i - 1];
            long long right = suffix[i + 1] - (n - i - 1) * indices[i];
            ans[indices[i]] = left + right;
        }
    }

    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long, vector<long long>> mp;
        vector<long long> ans(n, 0);
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        for (auto& [num, vec] : mp) {
            if (vec.size() > 1) {
                solve(vec, ans);
            }
        }
        return ans;
    }
};
