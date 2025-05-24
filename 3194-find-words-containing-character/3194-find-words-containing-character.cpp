class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n=words.size();
        vector<int>res;
        for(int i=0;i<n;i++){
            string word=words[i];
            for(auto &c:word){
                if(c==x){
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};