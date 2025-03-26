class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long totalAns = 0;
        
        for (auto& query : queries) {
            long long l = query[0], r = query[1];
            long long totalSteps = 0;
            
            for (long long power = 1, k = 0; power <= r; power *= 4, k++) {
                long long low = max(l, power);
                long long high = min(r, power * 4 - 1);
                
                if (low > high) continue; // No overlap
                
                long long count = high - low + 1;
                totalSteps += count * (k + 1);
            }
            
            totalAns += (totalSteps + 1) / 2;  // Ceiling division
        }
        return totalAns;
    }
};
