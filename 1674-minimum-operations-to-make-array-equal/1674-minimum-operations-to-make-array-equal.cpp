class Solution {
public:
    int minOperations(int n) {
        vector<int>vec;
        int sum=0;
        for(int i=0;i<n;i++){
          vec.push_back((2*i+1));
           sum+=(2*i+1);
        }
        int maxi=sum/n;
        int res=0;
        int m=vec.size();
        for(int j=0;j<(m/2);j++){
           res+=(maxi-vec[j]);
        }
        return res;
    }
};