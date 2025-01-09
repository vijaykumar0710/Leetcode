class Solution {
public:
class Trie{
    public:
    struct trieNode{
        trieNode *children[26];
        bool isEndofWord;
    };
    trieNode *getNode(){
        trieNode *newNode=new trieNode();
        newNode->isEndofWord=false;
        for(int i=0;i<26;i++){
            newNode->children[i]=NULL;
        }
        return newNode;
    }
    trieNode *root;
    Trie(){
        root=getNode();
    }
    void insert(string word){
        trieNode *crawler=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            if(!crawler->children[idx]){
                crawler->children[idx]=getNode();
            }
            crawler=crawler->children[idx];
        }
        crawler->isEndofWord=true;
    }
    bool startsWith(string prefix){
        trieNode *crawler=root;
        int i=0;
        for(;i<prefix.size();i++){
            int idx=prefix[i]-'a';
            if(!crawler->children[idx]){
                return false;
            }
            crawler=crawler->children[idx];
        }
        if(i==prefix.size()){
            return true;
        }
        return false;
    }
};
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            Trie prefixTrie;
            prefixTrie.insert(words[i]);
            if(prefixTrie.startsWith(pref)){
               cnt++;
            }
        } 
        return cnt;
    }
};