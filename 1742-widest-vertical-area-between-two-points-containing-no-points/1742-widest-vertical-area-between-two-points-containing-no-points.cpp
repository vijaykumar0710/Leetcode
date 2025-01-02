class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n=points.size();
        vector<int>vec(n);
        for(int i=0;i<n;i++){
            vec[i]=points[i][0];
        }
        int maxwidth=0;
        sort(begin(vec),end(vec));
        for(int i=1;i<n;i++){
            int width=vec[i]-vec[i-1];
            maxwidth=max(maxwidth,width);
        }
        return maxwidth;
    }
};