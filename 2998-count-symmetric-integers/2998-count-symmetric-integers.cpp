class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++){
            string s=to_string(i);
            if(s.size()%2==0){
                int n=s.size()/2;
                int x=0,y=0;
                for(int j=0;j<n;j++){
                    x+=(s[j]-'0');
                    y+=(s[j+n]-'0');
                }
                if(x==y)
                   cnt++;
            }
        }
        return cnt;
    }
};