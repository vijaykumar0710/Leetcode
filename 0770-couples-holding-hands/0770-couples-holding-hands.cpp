class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[row[i]]=i;
        }
        int minSwap=0;
        for(int i=0;i<n;i+=2){
            int first=row[i];
            int expected_pair;
            if(first%2==0)
              expected_pair=first+1;
            else
              expected_pair=first-1;
            if(expected_pair==row[i+1]) 
               continue;
            int idx=mp[expected_pair];
            swap(row[i+1],row[idx]);
            mp[row[i+1]]=i+1;
            mp[row[idx]]=idx;
            minSwap++;
        }
        return minSwap;
    }
};