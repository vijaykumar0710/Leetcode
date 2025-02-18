class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
        stack<int>minSt;
        stack<int>maxSt;
        for(int i=0;i<n;i++){
            minSt.push(tokens[n-i-1]);
            maxSt.push(tokens[i]);
        }
        int score=0;
        int maxScore=0;
        for(int i=0;i<n;i++){
            if(power>=minSt.top()){
              power-=minSt.top();
              minSt.pop();
              score++;
              maxScore=max(maxScore,score);
            }else{
                if(score>=1){
                    power+=maxSt.top();
                    maxSt.pop();
                    score--;
                    maxScore=max(maxScore,score);
                }
            }
        }
        return maxScore;
    }
};