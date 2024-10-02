class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp; 
        vector<int> result(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = 0;
        }
        int rank = 1;
        for (auto &it : mp) {
            it.second = rank;
            rank++;
        }
        for (int i = 0; i < arr.size(); i++) {
            result[i] = mp[arr[i]];
        }
        return result; 
    }
};
