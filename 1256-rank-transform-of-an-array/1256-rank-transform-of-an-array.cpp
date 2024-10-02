class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;  // To store unique elements in sorted order
        vector<int> result(arr.size());  // To store the final ranked array
        
        // Fill the map with the unique elements of the array
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = 0;  // Initially, assign 0 rank for all unique elements
        }
        
        // Assign ranks to the elements in the map based on their sorted order
        int rank = 1;
        for (auto &it : mp) {
            it.second = rank++;  // Assign rank to each unique element
        }
        
        // Populate the result array with the ranks using the original array
        for (int i = 0; i < arr.size(); i++) {
            result[i] = mp[arr[i]];  // Get the rank for each element from the map
        }
        
        return result;  // Return the array with ranks
    }
};
