class Solution {
public:
void binaryRepresentation(int num,vector<int>&vec){
       if (num == 0) {
            vec.push_back(0);
            return;
        }
    while(num>1){
        vec.push_back(num%2);
        num/=2;
    }
    vec.push_back(1);
    reverse(vec.begin(),vec.end());
}
    int minBitFlips(int start, int goal) {
        vector<int>vecs,vece;
        binaryRepresentation(start,vecs);
        binaryRepresentation(goal,vece);
        int n=vecs.size(),m=vece.size(); 
        int cnt=0;
        int minLen=min(m,n);
        for(int i=1;i<=minLen;i++){
          if(vecs[n-i]!=vece[m-i])
             cnt++;
        }
         for (int i = minLen + 1; i <= max(m, n); i++) {
            if (m > n) cnt += vece[m - i];
            else cnt += vecs[n - i];
        }
        return cnt;
    }
};