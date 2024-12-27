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
        int maxi=INT_MIN;
        for(int j=0;j<n-1;j++){
            int max_Ele=*max_element((vec2.begin()+(j+1)),vec2.end());
            maxi=max(maxi,vec1[j]+max_Ele);
        }
        return maxi;
    }
};