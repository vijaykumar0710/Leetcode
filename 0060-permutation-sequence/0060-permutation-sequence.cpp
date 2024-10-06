class Solution {
public:
string helper(string str,int k,string ans){
    int n=str.length();
    if(n==1){
        ans+=str;
        return ans;
    }
    int fact=1;
    for(int i=2;i<=n-1;i++){
        fact*=i;
    }
   int idx=(k%fact==0)?(k/fact-1):k/fact; 
   char ch=str[idx];
   string left=str.substr(0,idx);
   string right=str.substr(idx+1);
   return helper(left+right,k-fact*idx,ans+ch);
}
    string getPermutation(int n, int k) {
        string str="";
        for(int i=1;i<=n;i++){
            str+=to_string(i);
        }
        return helper(str,k,"");
    }
};