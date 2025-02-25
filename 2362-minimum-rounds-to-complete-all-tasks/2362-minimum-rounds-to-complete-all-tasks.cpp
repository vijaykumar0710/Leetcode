class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n=tasks.size();
        unordered_map<int,int>mp;
        for(auto &num:tasks){
            mp[num]++;
        }
        int minRounds=0;
           for(auto &[task,freq]:mp){ 
              if(freq==1)return -1;
               minRounds+=(freq/3);
               if(freq%3!=0){
              minRounds++;
               }
           }
        return minRounds;
    }
};