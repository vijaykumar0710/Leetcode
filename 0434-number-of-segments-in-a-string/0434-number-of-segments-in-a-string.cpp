class Solution {
public:
    int countSegments(string s) {
        string token;
        stringstream ss(s);
        int cnt=0;
        while(getline(ss,token,' ')){
           if(token.size()==0){
            cnt--;
           }
           cnt++;
        }
        return cnt;
    }
};