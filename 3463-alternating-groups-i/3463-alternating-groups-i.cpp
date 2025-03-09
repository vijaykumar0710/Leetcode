class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        for(int i=0;i<2;i++){
            colors.push_back(colors[i]);
        }
        int n=colors.size();
        int i=0,j=1,cnt=0;
        while(j<n){
            if(colors[j]==colors[j-1]){
                i=j;
                j++;
                continue;
            }
            if(j-i+1==3){
                i++;
                cnt++;
            }
            j++;
        }
        return cnt;
    }
};