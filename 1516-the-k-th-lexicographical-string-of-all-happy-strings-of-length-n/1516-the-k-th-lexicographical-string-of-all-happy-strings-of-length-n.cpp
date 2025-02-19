class Solution {
public:
void backtrack(int n,int idx,vector<string>&res,string &temp,vector<char>vec){
    if(temp.size()==n){
        res.push_back(temp);
        return;
    }
    for(int i=0;i<3;i++){
        if(temp.empty() || temp.back()!=vec[i]){
            temp+=vec[i];
            backtrack(n,i+1,res,temp,vec);
            temp.pop_back();
        }
    }
}
    string getHappyString(int n, int k) {
        vector<string>res;
        vector<char>vec={'a','b','c'};
        string temp="";
        backtrack(n,0,res,temp,vec);
        if(k>res.size()) return "";
        return res[k-1];
    }
};