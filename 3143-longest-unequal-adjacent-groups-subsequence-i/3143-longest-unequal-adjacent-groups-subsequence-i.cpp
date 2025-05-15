class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=groups.size();
        vector<int>group;
        int cnt=1;
        int i=1;
        for(;i<n;i++){
            if(groups[i]==groups[i-1]){
                cnt++;
            }else{
                group.push_back(i-1);
                cnt=1;
            }
        }
        group.push_back(i-1);
        vector<string>res;
        for(int j=0;j<group.size();j++){
            res.push_back(words[group[j]]);
        }
        return res;
    }
};