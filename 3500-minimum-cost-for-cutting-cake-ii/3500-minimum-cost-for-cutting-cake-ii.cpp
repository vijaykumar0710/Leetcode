class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int x=horizontalCut.size();
        int y=verticalCut.size();
        sort(begin(horizontalCut),end(horizontalCut),greater<int>());
        sort(begin(verticalCut),end(verticalCut),greater<int>());
        long long HCut=1,VCut=1;
        int i=0,j=0;
        long long cost=0;
        while(i<x && j<y){
            if(horizontalCut[i]>=verticalCut[j]){
              cost+=(VCut*horizontalCut[i]);
              HCut++;
              i++;
            }else{
                cost+=(HCut*verticalCut[j]);
                VCut++;
                j++;
            }
        }
            while(j<y){ 
            cost+=(HCut*verticalCut[j]);
                VCut++;
                j++;
            }
            while(i<x){ 
             cost+=(VCut*horizontalCut[i]);
              HCut++;
              i++;
        }
        return cost;
    }
};