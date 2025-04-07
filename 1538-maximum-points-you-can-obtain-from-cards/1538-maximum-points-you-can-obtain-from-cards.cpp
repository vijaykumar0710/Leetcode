class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
         vector<int>prefix(n),suffix(n);
        prefix[0]=cardPoints[0];
        suffix[n-1]=cardPoints[n-1];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+cardPoints[i];
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+cardPoints[i];
        }
        int max_score=max(prefix[k-1],suffix[n-k]);
        for(int i=0;i<k-1;i++){
            max_score=max(max_score,(prefix[i]+suffix[n-k+1+i]));
        }
        return max_score;
    }
};