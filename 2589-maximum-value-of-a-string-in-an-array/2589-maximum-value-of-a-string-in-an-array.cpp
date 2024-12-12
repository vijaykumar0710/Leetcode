class Solution {
public:
    int maximumValue(vector<string>& strs) {
       int maxi=0;
        for(auto &str:strs){
            int x=0;
             bool flag=true;
            for(auto &ch:str){
                if(!isdigit(ch)){
                   flag=false;
                   break;
                }
            }
            if(flag==false){
               x=str.size();
            }else{
               x=stoi(str);
            }
            maxi=max(maxi,x);
        }
        return maxi;
    }
};