class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int curr=0;
        int maxi=0,mini=0;
        for(auto &diff:differences){
            curr=curr+diff;
            maxi=max(maxi,curr);
            mini=min(mini,curr);
            if((upper-maxi)-(lower-mini)+1<=0)
                return 0;
        }
        return (upper-maxi)-(lower-mini)+1;
    }
};