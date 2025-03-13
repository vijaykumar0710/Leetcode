class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.size();
        vector<int>nums(n);
        for(int i=0;i<n;i++){  //converting char into value
            nums[i]=s[i]-'a';
        }
        vector<long long>suffix_sum(n);
        suffix_sum[n-1]=shifts[n-1];
        for(int i=n-2;i>=0;i--){  //suffix_sum
           suffix_sum[i]=shifts[i]+suffix_sum[i+1];
        }
        for(int i=0;i<n;i++){  //final_shift
          suffix_sum[i]+=nums[i];
        }
        for(int i=0;i<n;i++){  //change value into char
           s[i]=suffix_sum[i]%26+'a';
        }
        return s;
    }
};