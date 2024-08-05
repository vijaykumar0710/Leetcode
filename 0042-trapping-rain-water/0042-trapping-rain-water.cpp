class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
       // if (n < 3) return 0; 
        
        vector<int> prevGre(n);
        prevGre[0] = height[0];
        for (int i = 1; i < n; i++) {
            prevGre[i] = max(prevGre[i - 1], height[i]);
        }

        vector<int> nextGre(n);
        nextGre[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            nextGre[i] = max(nextGre[i + 1], height[i]);
        }

        int trap_rain = 0;
        for (int i = 1; i < n - 1; i++) {
            int minHeight = min(prevGre[i], nextGre[i]);
            if (minHeight > height[i]) {
                trap_rain += minHeight - height[i];
            }
        }

        return trap_rain;
    }
};
