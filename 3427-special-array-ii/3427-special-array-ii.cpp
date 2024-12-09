class Solution {
public:
    bool bSearch(vector<int>& vi, int sp, int ep) {
        int l = 0;
        int r = vi.size()-1;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(vi[mid] < sp) {
                l = mid+1;
            } else if(vi[mid] > ep) {
                r = mid-1;
            } else {
                //we found violating index
                return true;
            }
        }

        return false;

    }

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int m = queries.size();
        int n = nums.size();

        vector<int> vi; //violating indices ka list hai ye

        for(int i = 1; i < n; i++) { //O(n)
            if(nums[i]%2 == nums[i-1]%2) {
                vi.push_back(i); //it will always be in sorted order
            }
        }

        vector<bool> result(m, false);

        for(int i = 0; i < m; i++) { //O(m)
            int start = queries[i][0];
            int end = queries[i][1];

            bool hasViolatingIndexInRange = bSearch(vi, start+1, end); //log(n)

            if(hasViolatingIndexInRange == false) { //Did not find any violating index
                result[i] = true;
            }
        }

        return result;

    }
};