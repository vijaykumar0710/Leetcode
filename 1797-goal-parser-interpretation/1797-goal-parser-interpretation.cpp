class Solution {
public:
    string interpret(string command) {
        int n=command.size();
        string result="";
        for(int i=0;i<n;i++){
            if(command[i]=='G')result+="G";
            if(command[i]=='('){
                if(command[i+1]==')'){
                    result+="o";
                }else{
                    result+="al";
                }
            }
        }
        return result;
    }
};