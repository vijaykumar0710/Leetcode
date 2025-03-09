class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for(int i=0;i<k-1;i++){
            colors.push_back(colors[i]);
        }
        int cnt=0;
        int n=colors.size();
        int j=1,i=0;
       while(j<n){
        if(colors[j]==colors[j-1]){
            i=j;
            j++;
            continue;
        }
        if(j-i+1==k){
            cnt++;
            i++;
         }
         j++;
       }
       return cnt;
    }
};