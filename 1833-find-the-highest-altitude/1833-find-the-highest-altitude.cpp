class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int prefixSum=0;
        int highAlt=0;
        for(int i=0;i<gain.size();i++){
            prefixSum+=gain[i];
            highAlt=max(highAlt,prefixSum);
        }   
        return highAlt;
    }
};