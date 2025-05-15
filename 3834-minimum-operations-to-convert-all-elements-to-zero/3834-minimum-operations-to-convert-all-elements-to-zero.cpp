class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>pairs;
        for(int i=0;i<n;i++){
            pairs.push_back({nums[i],i});
        }
        sort(pairs.begin(),pairs.end());
        set<int>st{n};
        int ans=0;
        for(int i=0;i<n;i++){
             st.insert(pairs[i].second);
            if(pairs[i].first!=0) ans++;
             while(i+1<n && pairs[i].first==pairs[i+1].first){
                int nextSmallerIdx=*st.upper_bound(pairs[i].second);
                 int nextsameEleIdx=pairs[i+1].second;
                 if(nextSmallerIdx<nextsameEleIdx) break;
                 i++;
                 st.insert(pairs[i].second);
             }
        }
        return ans;
    }
};