class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>have_balls;
        for(int i=0;i<n;i++){
            if(boxes[i]=='1'){
                have_balls.push_back(i);
            }
        }
        vector<int>result;
        for(int j=0;j<n;j++){
            int diff=0;
            for(int k=0;k<have_balls.size();k++){
                diff+=abs(j-have_balls[k]);
            }
            result.push_back(diff);
        }
        return result;
    }
};