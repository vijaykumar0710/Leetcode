class Solution {
public:
void solve(string &s,unordered_map<char,string>&mp,int idx,string &curr,vector<string>&ans){
    if(idx==s.size()){
        ans.push_back(curr);
        return;
    }
    char ch=s[idx];
    for(auto letter:mp[ch]){
        curr+=letter;
        solve(s,mp,idx+1,curr,ans);
        curr.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string>ans;
        unordered_map<char,string>mp;
        mp['2']={"abc"};
        mp['3']={"def"};
        mp['4']={"ghi"};
        mp['5']={"jkl"};
        mp['6']={"mno"};
        mp['7']={"pqrs"};
        mp['8']={"tuv"};
        mp['9']={"wxyz"};
        string curr;
       solve(digits,mp,0,curr,ans);
       return ans;
    }
};