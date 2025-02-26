class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.size();
        if(n<3) return false;
        int a=0,b=0;
        int alice=0,bob=0;
        for(int i=0;i<n;i++){
           if(colors[i]=='A'){
            a++;
           if(b>2) bob+=(b-2);
           b=0;
           }else{
           if(a>2) alice+=(a-2);
           a=0;
            b++;
           }
        }
        if(a>2) alice+=(a-2);
        if(b>2) bob+=(b-2);
        return alice>bob;
    }
};