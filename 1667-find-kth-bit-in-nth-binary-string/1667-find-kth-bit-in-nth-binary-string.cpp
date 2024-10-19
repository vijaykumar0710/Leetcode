class Solution {
public:
string invert(string prev){
     string str=prev;
    for(auto &ch:str){
        ch=(ch=='0')?'1':'0';
    }
    return str;
}
string helper(int n){
    if(n==1) return "0";
    string prev=helper(n-1);
    string inverted=invert(prev);
    reverse(begin(inverted),end(inverted));
    return prev+"1"+inverted;
}
    char findKthBit(int n, int k) {
        string num=helper(n);
        return num[k-1];
    }
};