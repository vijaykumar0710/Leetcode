class Solution {
public:
int minSwapsToMakePairs(vector<int>& row) {
    int n = row.size();
    unordered_map<int, int> pos;
    for(int i = 0; i < n; i++) {
        pos[row[i]] = i;
    }

    int swaps = 0;
    for(int i = 0; i < n; i += 2) {
        int first = row[i];
        int expected_pair;

        // We want pair such that difference is 1
        if (first % 2 == 0)
            expected_pair = first + 1;
        else
            expected_pair = first - 1;

        // If already paired correctly, continue
        if(row[i+1] == expected_pair) continue;

        // Swap expected pair to the correct position
        int idx = pos[expected_pair];

        // Update positions in map after swap
        swap(row[i+1], row[idx]);
        pos[row[idx]] = idx;
        pos[row[i+1]] = i+1;

        swaps++;
    }

    return swaps;
}
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        return minSwapsToMakePairs(row);
    }
};