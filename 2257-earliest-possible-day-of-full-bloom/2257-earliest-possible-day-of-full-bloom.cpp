class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            vec.push_back({growTime[i],plantTime[i]});
        }
        sort(vec.begin(),vec.end(), [](pair<int, int>& a,pair<int, int>& b) {
        return a.first > b.first; // Descending order
    });
        vector<int>prefix_sum(n,0);
        prefix_sum[0]=vec[0].second;
        for(int i=1;i<n;i++){
           prefix_sum[i]=prefix_sum[i-1]+vec[i].second;
        }
        int maxi=vec[0].first+vec[0].second;
        for(int i=1;i<n;i++){
            int time=prefix_sum[i]+vec[i].first;
            maxi=max(maxi,time);
        }
        return maxi;
    }
};