class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.length();
        unordered_map<char,int>mp;
        mp['A']=65;
         mp['E']=69;
          mp['I']=73;
           mp['O']=79;
            mp['U']=85;
             mp['a']=97;
              mp['e']=101;
               mp['i']=105;
                mp['o']=111;
                 mp['u']=117;
                 int i=0,j=n-1;
                 int count1=0,count2=0;
                 while(i<j){
                  if(mp.find(s[i])!=mp.end()) count1++;
                  if(mp.find(s[j])!=mp.end()) count2++;
                  i++;
                  j--;
                 }
        if(count1==count2){
            return true;
        }
        return false;
    }
};