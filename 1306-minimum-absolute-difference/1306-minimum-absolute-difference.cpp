class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        sort(begin(arr),end(arr));
        vector<vector<int>>ans;
        int mini=INT_MAX;
        for(int i=1;i<n;i++){
            int x=abs(arr[i]-arr[i-1]);
            mini=min(mini,x);
        }
         for(int i=1;i<n;i++){
            int x=abs(arr[i]-arr[i-1]);
            if(mini==x){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};