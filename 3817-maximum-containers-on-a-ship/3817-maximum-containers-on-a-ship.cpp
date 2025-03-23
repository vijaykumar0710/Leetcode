class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int temp=0;
        int i=0;
        int ans=0;
        while(i<n*n){
            temp=temp+w;
            if(temp<=maxWeight){
                ans=i+1;
            }
            i++;
        }
        return ans;
    }
};