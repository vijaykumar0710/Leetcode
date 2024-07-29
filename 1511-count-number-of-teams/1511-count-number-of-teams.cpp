class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count = 0;
        
        for (int i = 1; i < n - 1; i++) {
            int left_smaller = 0;
            int left_larger = 0;
            int  right_smaller = 0;
            int  right_larger = 0;
            
            for (int j = 0; j < i; j++) {
                if (rating[j] < rating[i]) left_smaller++;
                if (rating[j] > rating[i]) left_larger++;
            }
            
            for (int k = i + 1; k < n; k++) {
                if (rating[k] < rating[i]) right_smaller++;
                if (rating[k] > rating[i]) right_larger++;
            }
            
            count += left_smaller * right_larger + left_larger * right_smaller;
        }
        
        return count;
    }
};
