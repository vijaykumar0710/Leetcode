class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        for(int i=0;i<chalk.size();i++){
            sum+=chalk[i];
        }
        int rem=k%sum;
        for(int i=0;i<chalk.size();i++){
            if(rem<chalk[i]){
                return i;
            }
            rem-=chalk[i];
        }
        return -1;
    }
};