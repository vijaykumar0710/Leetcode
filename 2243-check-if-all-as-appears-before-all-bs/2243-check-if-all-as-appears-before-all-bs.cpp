class Solution {
public:
    bool checkString(string s) {
        int cnt_a=0;
        for(auto &ch:s){
            if(ch=='a'){
                cnt_a++;
            }
        }
        if(cnt_a==0) return true;
        for(auto &ch:s){
            if(ch=='a') cnt_a--;
            else if(ch=='b' && cnt_a!=0) return false;
        }
        return true;
    }
};