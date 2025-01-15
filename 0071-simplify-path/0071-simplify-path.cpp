class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        vector<string>tokens;
        while(getline(ss,token,'/')){
            if(token=="." || token=="")continue;

          else if(token==".."){
               if(!tokens.empty()){
                tokens.pop_back();
               }
            }
            else tokens.push_back(token);
        }
        string result="";
        
        if(tokens.empty())return "/";

        for(int i=0;i<tokens.size();i++){
            result+=('/'+tokens[i]);
        }
        return result;
    }
};