class Solution {
public:
    int heightChecker(vector<int>& heights) {
         int n=heights.size();
         vector<int>height;
          for(auto &idx:heights){
            height.push_back(idx);
         }
         sort(begin(heights),end(heights));
         int idx_count=0;
         for(int i=0;i<n;i++){
            if(height[i]!=heights[i]){
                idx_count++;
            }
         }
         return idx_count;
    }
};