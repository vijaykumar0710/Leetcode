class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
        long long capacitySum=accumulate(begin(capacity),end(capacity),0LL);
        long long rocksSun=accumulate(begin(rocks),end(rocks),0LL);
        if(rocksSun+additionalRocks>capacitySum) return n;
        vector<int>helper(n);
        for(int i=0;i<n;i++){
            helper[i]=capacity[i]-rocks[i];
        }
        sort(begin(helper),end(helper));
        int cnt=0;
        for(int i=0;i<n;i++){
            if(additionalRocks>=helper[i]){
                cnt++;
                additionalRocks-=helper[i];
                if(additionalRocks<0) break;
            }
        }
        return cnt;
    }
};