class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
    for(int i=0;i<s.size();i++){
        sum+=((123-s[i])*(i+1));
       }
       return sum;
    }
};