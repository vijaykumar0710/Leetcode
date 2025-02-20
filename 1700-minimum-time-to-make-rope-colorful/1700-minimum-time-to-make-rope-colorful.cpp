class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        if(n==1) return 0;
        int mini=0;
        int i=0,j=1;
        while(j<n){
            if(colors[i]==colors[j]){
                if(neededTime[i]<neededTime[j]){
                    mini+=neededTime[i];
                    neededTime[i]=neededTime[j];
                }
                else{
                    mini+=neededTime[j];
                    neededTime[j]=neededTime[i];
                }
            }
            i++;
            j++;
        }
        return mini;
    }
};