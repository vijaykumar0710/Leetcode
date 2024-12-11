class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        map<int, int> events;
        int max_beauty=0;
        vector<pair<int,int>>ranges;
        for(int i=0;i<n;i++){
            ranges.push_back({nums[i]-k,nums[i]+k});
        }
        for (auto range : ranges) {
        events[range.first]++;
        events[range.second + 1]--; // End + 1 to mark the range end
        }
        int maxOverlap = 0, currentOverlap = 0, bestNumber = 0;

      for (auto &event : events) {
        currentOverlap += event.second;
        if (currentOverlap > maxOverlap) {
            maxOverlap = currentOverlap;
            bestNumber = event.first;
        }
      }
      return maxOverlap;
    }
};