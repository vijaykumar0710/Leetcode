class Solution {
public:
  bool solve(int num){
    int original=num;
    while(num>0){ 
      int divider=num%10;
      if(divider==0 || original%divider!=0){
        return false;
      }
      num/=10;
    }
      return true;
  }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>result;
        for(int i=left;i<=right;i++){
           if(solve(i)) result.push_back(i);
        }
        return result;
    }
};