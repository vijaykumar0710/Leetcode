class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int sum=0;
        int maxint=0;
        unordered_set<int>st;
        for(auto &num:banned){
            st.insert(num);
        }
        int i=1;
        while(i<=n){
            if(st.find(i)==st.end()){
                sum+=i;
                if(sum<=maxSum){ 
                maxint++;
                }
            }
            i++;
        }
        return maxint;
    }
};