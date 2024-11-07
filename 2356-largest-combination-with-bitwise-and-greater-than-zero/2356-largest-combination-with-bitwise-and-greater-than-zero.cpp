class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n=candidates.size();
       int largest=INT_MIN;
        for(int bitpos=0;bitpos<24;bitpos++){
            int cnt=0;
         for(auto num:candidates){
            if((num&(1<<bitpos))!=0){
               cnt++;
            }
         }
         largest=max(largest,cnt);
        }
        return largest;
    }
};