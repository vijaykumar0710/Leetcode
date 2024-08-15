class Solution {
public:
    int maxDepth(string s) {
        int maxi=0;
        int prev=0;
        for(auto &ch:s){
            if(ch=='('){
                prev++;
            }
            maxi=max(maxi,prev);
            if(ch==')'){
                prev--;
            } 
        }
        return maxi;
    }
};