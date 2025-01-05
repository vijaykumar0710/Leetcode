class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int>arr_diff(n,0);

        for(auto shift:shifts){
            int start=shift[0];
            int end=shift[1];
            int dir=shift[2];
            if(dir==0){
                arr_diff[start]+=-1;
               if(end+1<n)arr_diff[end+1]+=1;
            }else{
                arr_diff[start]+=1;
                if(end+1<n)arr_diff[end+1]+=-1;
            }
        }

        for(int i=1;i<n;i++){
            arr_diff[i]+=(arr_diff[i-1]);
        }
        
       for (int i = 0; i < n; i++) {
            int shift_value = arr_diff[i] % 26;
            s[i] = (s[i] - 'a' + shift_value + 26) % 26 + 'a';
        }

        return s;
    }
};