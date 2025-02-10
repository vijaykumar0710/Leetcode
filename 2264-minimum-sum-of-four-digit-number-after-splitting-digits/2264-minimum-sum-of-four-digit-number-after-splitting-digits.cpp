class Solution {
public:
    int minimumSum(int num) {
    int n=num;
    vector<int>vec;
    while(n){
     vec.push_back(n%10);
     n/=10;
      }
      sort(vec.begin(),vec.end());
      int a=vec[0]*10+vec[2];
      int b=vec[1]*10+vec[3];
      return a+b;
    }
};