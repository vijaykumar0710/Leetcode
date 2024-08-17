class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g),end(g));
        sort(begin(s),end(s));
        int i=0,j=0;
        while(j<s.size() && i<g.size()){
           if(s[j]>=g[i]){
               i++;
           }
           j++;
        }
        return i;
    }
};