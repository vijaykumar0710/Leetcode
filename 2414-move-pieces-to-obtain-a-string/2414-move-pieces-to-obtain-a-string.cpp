class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.size();
        int i=0,j=0;
        while(i<n || j<n){

           while(start[i]=='_') i++;
           while(target[j]=='_') j++;

           if(start[i]!=target[j]) return false;
         
           if (start[i] == 'L' && i < j) return false; 
           if (start[i] == 'R' && i > j) return false; 

           i++;
           j++;
        }
        return true;
    }
};