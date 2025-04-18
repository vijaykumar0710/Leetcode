class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
       int idx=0;
       int i=0;
       while(i<n){
        int freq=0;
        char curr_char=chars[i];
        while(i<n && chars[i]==curr_char){
            freq++;
            i++;
        }
        chars[idx]=curr_char;
        idx++;
        if(freq>1){
            string str=to_string(freq);
            for(auto &ch:str){
                chars[idx]=ch;
                idx++;
            }
          }
       }
       return idx;
    }
};