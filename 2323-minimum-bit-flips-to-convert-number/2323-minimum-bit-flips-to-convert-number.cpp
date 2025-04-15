class Solution {
public:
void binaryRepresentation(int num,vector<int>&vec){
       if (num == 0) {
            vec[0]=0;
            return;
        }
        int i=0;
    while(num>1){
        vec[i]=(num%2);
        i++;
        num/=2;
    }
    vec[i]=1;
    reverse(vec.begin(),vec.end());
}
    int minBitFlips(int start, int goal) {
        vector<int>vecs(65,0),vece(65,0);
        binaryRepresentation(start,vecs);
        binaryRepresentation(goal,vece); 
        int cnt=0;
        int i=64;
        while(i>=0){
          if(vecs[i]!=vece[i])
             cnt++;
             i--;
        }
        return cnt;
    }
};