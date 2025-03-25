class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>wordlist(wordList.begin(),wordList.end());
        //agar endword hi missing hain toh ans 0
        if(wordlist.find(endWord)==wordlist.end()) return 0;

        queue<pair<string,int>>q;
        q.push({beginWord,1});

        while(!q.empty()){
            auto [word,count]=q.front();
            q.pop();
           // mil gya toh count return karo
            if(word==endWord) return count;
            
            for(int i=0;i<word.size();i++){
                char originalChar=word[i];
                for(char c='a';c<='z';c++){
                    if(c==originalChar) continue;
                    word[i]=c;
                    if(wordlist.find(word)!=wordlist.end()){
                        q.push({word,count+1});
                        wordlist.erase(word);
                    }
                }
                // wapas original word me revert kar do
                word[i]=originalChar;
            }
        }
        return 0;
    }
};