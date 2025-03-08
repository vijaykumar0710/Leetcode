class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int cnt=INT_MAX;
        for(int i=0;i<=n-k;i++){
            int w=0;
            for(int j=i;j<k+i;j++){
                if(blocks[j]=='W'){
                   w++;
                }
            }
            cnt=min(cnt,w);
        }
        return cnt;
    }
};