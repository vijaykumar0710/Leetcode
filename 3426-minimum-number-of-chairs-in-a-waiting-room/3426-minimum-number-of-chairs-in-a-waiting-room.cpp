class Solution {
public:
    int minimumChairs(string s) {
        int n=s.size();
        int count=0;
        int maxi=INT_MIN;
        for(auto &ch:s){
            if(ch=='E'){
                count++;
                maxi=max(count,maxi);
            }else{
                count--;
            }
        }
        return maxi;
    }
};