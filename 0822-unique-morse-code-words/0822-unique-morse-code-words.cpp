class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
       string arr[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

unordered_map<char,string>mp;
int j=0;
       for(char i='a';i<='z';i++){
          mp[i]=arr[j];
          j++;
       }
       unordered_set<string>st;
       for(auto &word:words){
        string str="";
        for(auto &ch:word){
           str+=mp[ch];
        }
        st.insert(str);
       }
       return st.size();
    }
};