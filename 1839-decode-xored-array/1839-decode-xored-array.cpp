class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n=encoded.size();
        vector<int>res(n+1);
        res[0]=first;
        for(int i=0;i<n;i++){
        res[i+1]=encoded[i]^res[i];
        }
        return res;
    }
};