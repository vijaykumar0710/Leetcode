class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();
        long long capacitySum=accumulate(begin(capacity),end(capacity),0LL);
        long long rocksSun=accumulate(begin(rocks),end(rocks),0LL);
        if(rocksSun+additionalRocks>capacitySum) return n;
        for(int i=0;i<n;i++){
            capacity[i]=capacity[i]-rocks[i];
        }
        sort(begin(capacity),end(capacity));
        int cnt=0;
        for(int i=0;i<n;i++){
            if(additionalRocks>=capacity[i]){
                cnt++;
                additionalRocks-=capacity[i];
                if(additionalRocks<0) break;
            }
        }
        return cnt;
    }
};