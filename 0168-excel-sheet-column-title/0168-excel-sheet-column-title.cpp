class Solution {
public:
    string convertToTitle(int columnNumber) {
        unordered_map<int,char>mp;
        mp[0]='Z';
        for(int i=1;i<=25;i++){
            mp[i]=char(i+64);
        }
        string st;
        while(columnNumber>0){
             int rem=columnNumber%26;
           if(rem==0){
             st+='Z';
             columnNumber--;
           }else{ 
                st+=mp[rem];
           }
            columnNumber=columnNumber/26;
        }
        reverse(st.begin(),st.end());
        return st;
    }
};