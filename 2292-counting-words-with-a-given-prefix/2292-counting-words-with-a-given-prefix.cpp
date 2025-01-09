struct trieNode{
        trieNode *children[26];//bluprint
        bool isEndofWord;
        int cnt;
    };
    trieNode *getNode(){  //constructor
        trieNode *newNode=new trieNode();
        newNode->isEndofWord=false;
        newNode->cnt=0;
        for(int i=0;i<26;i++){
            newNode->children[i]=NULL;
        }
        return newNode;
    }
class Trie{
    public:
    trieNode *root;
    Trie(){
        root=getNode();
    }
    void insert(string &word){
        trieNode *crawler=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            if(!crawler->children[idx]){
                crawler->children[idx]=getNode();
            }
            crawler=crawler->children[idx];
            crawler->cnt++;
        }
        crawler->isEndofWord=true;
    }
    int startsWithCnt(string &prefix){
        trieNode *crawler=root;
        int i=0;
        for(char &ch:prefix){
            int idx=ch-'a';
            if(!crawler->children[idx]){
                return 0;
            }
            crawler=crawler->children[idx];
        }
       return crawler->cnt;
    }
};
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size();
        Trie prefixTrie;  //make object
        for(int i=0;i<n;i++){
            prefixTrie.insert(words[i]); 
        } 
        return prefixTrie.startsWithCnt(pref);
    }
};