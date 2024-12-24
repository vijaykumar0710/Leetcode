class Solution {
public:
int counter(string sentence){
    stringstream s(sentence);
    string word;
    int count=0;
    while(s>>word){
        count++;
    }
    return count;
}
    int mostWordsFound(vector<string>& sentences) {
        int max_words=0;
        for(auto &sentence:sentences){
           max_words=max(max_words,counter(sentence));
        }
        return max_words;
    }
};