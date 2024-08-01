class Solution {
public:
    int countSeniors(vector<string>& details) {
       int sum=0;
       for(auto &detail:details){
      string ch=detail.substr(11,2); 
      int x=stoi(ch);
      if(x>60) sum++;
       }
        return sum;
    }
};