class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int MIN=arrays[0].front();
        int MAX=arrays[0].back();

        int result=0;
        
for(int i=1;i<arrays.size();i++){
    int currMin=arrays[i].front();
    int currMax=arrays[i].back();

    result=max({result,abs(MIN-currMax),abs(MAX-currMin)});
    MAX=max(currMax,MAX);
    MIN=min(MIN,currMin);
       }
       return result;
    }
};