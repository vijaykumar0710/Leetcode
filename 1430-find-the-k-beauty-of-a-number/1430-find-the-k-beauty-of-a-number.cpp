class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s=to_string(num);
        int n=s.size();
        int cnt=0;
        for(int i=0;i<=n-k;i++){
          string temp=s.substr(i,k);
          int x=stoi(temp);
          if(x!=0 && num%x==0)
            cnt++;
        }
        return cnt;
    }
};