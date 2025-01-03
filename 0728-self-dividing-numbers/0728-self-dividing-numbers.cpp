class Solution {
public:
  bool solve(int num,int number){
      int divider=num%10;
      if(divider==0 || number%divider!=0){
        return false;
      }
      if(num/10>0){
     return solve(num/10,number);
      }
      return true;
  }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>result;
        for(int i=left;i<=right;i++){
           if(solve(i,i)){
            result.push_back(i);
           }
        }
        return result;
    }
};