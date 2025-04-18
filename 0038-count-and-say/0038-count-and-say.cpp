class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string str=countAndSay(n-1);
        string res="";
        int freq=1;
        char ch=str[0];
        for(int i=1;i<str.size();i++){
            if(str[i]==ch){ 
               freq++;
            } else{
            res+=(to_string(freq)+ch);
            freq=1;
            ch=str[i];
           }
        }
        res+=(to_string(freq)+ch);
        return res;
    }
};