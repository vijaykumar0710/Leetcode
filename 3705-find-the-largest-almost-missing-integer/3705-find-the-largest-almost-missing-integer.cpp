class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<=n-k;i++){
            unordered_set<int>st;
            for(int j=i;j<k+i;j++){
                if(st.find(nums[j])==st.end()){ 
                mp[nums[j]]++;
                st.insert(nums[j]);
                }
            }
        }
        int miss=-1;
        for(auto [x,freq]:mp){
            if(freq==1){
                miss=max(miss,x);
            }
        }
        return miss;
    }
};