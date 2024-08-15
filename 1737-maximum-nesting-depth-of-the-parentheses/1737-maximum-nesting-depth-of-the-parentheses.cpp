class Solution {
public:
    int maxDepth(string s) {
        int open=0;
        int close=0;
        int maxi=0;
        int prev=0;
        for(auto &ch:s){
            if(ch=='('){
                open++;
                prev++;
            }
            maxi=max(maxi,prev);
            if(ch==')'){
                close++;
                prev--;
            } 
        }
        return maxi;
    }
};