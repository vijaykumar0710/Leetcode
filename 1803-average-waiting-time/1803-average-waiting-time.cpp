class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        double total=customers[0][0]+customers[0][1];
        double totalWait=0;
        double result=customers[0][1];

        for(int i=1;i<n;i++){
            int arrival=customers[i][0];
            int wait=customers[i][1];
        if((total-arrival)>0){ 
        total=(arrival+wait)+(total-arrival);
        totalWait=total-arrival;
        result+=totalWait;
           }else{
            result+=customers[i][1];
            total=customers[i][0]+customers[i][1];
           }
        }
        return result/n;
    }
};