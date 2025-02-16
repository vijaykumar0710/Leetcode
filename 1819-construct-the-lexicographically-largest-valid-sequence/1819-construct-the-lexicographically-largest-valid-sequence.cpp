class Solution {
public:
    int m;
    
    bool backtrack(vector<int>& res, vector<bool>& used, int idx, int n) {
        if (idx == m) return true;
        
        if (res[idx] != 0) return backtrack(res, used, idx + 1, n); 
        
        for (int num = n; num >= 1; num--) { 
            if (!used[num]) {
                int j = (num > 1) ? idx + num : idx; 
                if (j < m && res[j] == 0) { 
                    res[idx] = num;
                    res[j] = num;
                    used[num] = true;
                    if (backtrack(res, used, idx + 1, n)) return true; 
                    res[idx] = 0;
                    res[j] = 0;
                    used[num] = false;
                }
            }
        }
        return false; 
    }

    vector<int> constructDistancedSequence(int n) {
        m = 2 * n - 1;
        vector<int> res(m, 0);
        vector<bool> used(n + 1, false); 

        backtrack(res, used, 0, n);
        return res;
    }
};
