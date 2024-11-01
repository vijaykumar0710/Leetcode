class Solution {
public:
    string makeFancyString(string s) {
        queue<char>que;
        int count=1;
        char prev='@';
        for(auto ch:s){
            if(ch==prev){
             count++;
            }else{
                count=1;
            }
            prev=ch;
          if(count<3){
            que.push(ch);
          }
        }
        string str;
        while(!que.empty()){
         str+=que.front();
         que.pop();
        }
        return str;
    }
};