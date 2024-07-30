class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        int right_a=0;
        for(int i=n-1;i>=0;i--){
        if(s[i]=='a') right_a++;
        }

         int count=INT_MAX;
          int left_b=0;

        for(int j=0;j<n;j++){
        if(s[j]=='a'){
            right_a--;
        }
        count=min(count,left_b+right_a);
        if(s[j]=='b') left_b++;
           }
        return count;
    }
};