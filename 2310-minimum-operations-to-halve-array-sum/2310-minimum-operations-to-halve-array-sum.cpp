class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double,vector<double>>maxPq;
        long long totalSum=0;
        for(auto num:nums){
            maxPq.push(num);
            totalSum+=num;
        }
        double sum=0;
        int k=0;
        while(sum<(totalSum/2.0)){
            k++;
            double x=maxPq.top();
            maxPq.pop();
            sum+=x/2.0;
            maxPq.push(x/2.0);
        }
        return k;
    }
};