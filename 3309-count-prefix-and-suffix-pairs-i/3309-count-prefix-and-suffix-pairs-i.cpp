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
    for(int i=0;i<word.length();i++){
        int idx=word[i]-'a';
        if(!crawler->children[idx]){
            crawler->children[idx]=getNode();
        }
        crawler=crawler->children[idx];
    }
    crawler->isEndofWord=true;
   }
   bool serachPrefix(string prefix){
    trieNode *crawler=root;
    for(int i=0;i<prefix.length();i++){
        int idx=prefix[i]-'a';
        if(!crawler->children[idx]){
            return false;
        }
        crawler=crawler->children[idx];
    }
    return true;
   }
};
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int count=0;
        for(int j=0;j<n;j++){
            Trie prefixTrie;
            Trie suffixTrie;
            prefixTrie.insert(words[j]);

            string reversed=words[j];
            reverse(begin(reversed),end(reversed));
            suffixTrie.insert(reversed);

            for(int i=0;i<j;i++){
                if(words[i].length()>words[j].length()){
                    continue;
                }
                string rev=words[i];
                reverse(begin(rev),end(rev));
                if(prefixTrie.serachPrefix(words[i])==true && suffixTrie.serachPrefix(rev)==true){
                    count++;
                }
            }
        }
        return count;
    }
};