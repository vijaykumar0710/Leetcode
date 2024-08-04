class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> vec;
        for (int i = 0; i < n; i++) {
            long long sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                vec.push_back(sum);
            }
        }
        sort(begin(vec), end(vec));
        long long result = 0; 
        for (int i = left - 1; i < right; i++) {
            result += vec[i];
            result %= (1000000007);
        }
        return result;
    }
};
