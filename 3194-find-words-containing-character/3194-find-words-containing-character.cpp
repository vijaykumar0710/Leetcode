class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>res;
        for(int j=0;j<words.size();j++){
            string word=words[j];
            for(int i=0;i<word.size();i++){
                if(word[i]==x){
                       res.push_back(j);
                       break;
                }
            }
        }
        return res;
    }
};