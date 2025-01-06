class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>prefix(n);
        prefix[0]=boxes[0]=='1'?1:0;
        for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+(boxes[i]=='1'?1:0);
        }
        vector<int>suffix(n);
        suffix[n-1]=boxes[n-1]=='1'?1:0;
        for(int i=n-2;i>=0;i--){
        suffix[i]=suffix[i+1]+(boxes[i]=='1'?1:0);
        }
        vector<int>prefix_sum(n);
        prefix_sum[0]=0;
        for(int i=1;i<n;i++){
        prefix_sum[i]=prefix_sum[i-1]+prefix[i-1];
        }
        vector<int>suffix_sum(n);
        suffix_sum[n-1]=0;
        for(int i=n-2;i>=0;i--){
        suffix_sum[i]=suffix[i+1]+suffix_sum[i+1];
        }
        vector<int>result;
        for(int i=0;i<n;i++){
            result.push_back(prefix_sum[i]+suffix_sum[i]);
        }
        return result;
    }
};