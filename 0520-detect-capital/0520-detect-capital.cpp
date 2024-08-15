class Solution {
public:
bool allCapital(string word){
    for(auto &ch:word){ 
    if(ch<'A' || ch>'Z') return false;
    }
    return true;
}
bool allSmall(string word){
    for(auto &ch:word){ 
    if(ch<'a' || ch>'z') return false;
    }
    return true;
}
    bool detectCapitalUse(string word) {
      if(allCapital(word) || allSmall(word) || allSmall(word.substr(1))){
        return true;
      }
      return false;
    }
};