class Solution {
public:
    int getLucky(string s, int k) {
        int n=s.length();
        string numstr="";
        for(auto &ch:s){
            numstr+=to_string(ch-'a'+1);
        }
        int sum;
            while(k>0){
                sum=0;
            for(auto ch:numstr){
               sum+=ch-'0';
            }
            k--;
            numstr=to_string(sum);
        }
        return sum;
    }
};