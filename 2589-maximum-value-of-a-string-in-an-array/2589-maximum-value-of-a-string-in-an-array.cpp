class Solution {
public:
    int maximumValue(vector<string>& strs) {
       unsigned long maxi=0;
        for(auto &str:strs){
            unsigned long x=0;
            bool flag=true;
            for(auto &ch:str){
                if(isdigit(ch)){
                   continue;
                }else{
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