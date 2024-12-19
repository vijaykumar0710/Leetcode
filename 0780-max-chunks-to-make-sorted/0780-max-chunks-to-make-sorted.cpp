class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int maxNum=arr[0];
        int chunks=0;
        for(int i=0;i<n;i++){
            maxNum=max(maxNum,arr[i]);
            if(maxNum==i){
                chunks++;
            }
        }
        return chunks;
    }
};