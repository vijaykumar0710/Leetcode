class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<int>vec1;
        vector<int>vec2;
        for(int i=0;i<n;i++){
            vec1.push_back(values[i]+i);
            vec2.push_back(values[i]-i);
        }
        int prev_max=vec2[n-1];
        for(int j=n-1;j>=0;j--){
        prev_max=max(prev_max,vec2[j]);
         vec2[j]=prev_max;
        }
        int maxi=INT_MIN;
       for(int k=0;k<n-1;k++){
        maxi=max(maxi,(vec1[k]+vec2[k+1]));
       }
       return maxi;
    }
};