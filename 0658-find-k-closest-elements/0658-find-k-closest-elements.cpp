class Solution {
public:
    int inArray(vector<int>& arr, int x) {
        int l = 0, r = arr.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x) {
                return mid;
            } else if (arr[mid] > x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int idx = inArray(arr, x);

        if (idx == -1) {
            int left = 0, right = n - 1;
            while (right - left >= k) {
                if (abs(arr[left] - x) > abs(arr[right] - x)) {
                    left++;
                } else {
                    right--;
                }
            }
            return vector<int>(arr.begin() + left, arr.begin() + right + 1);
        } else {
            int left = idx - 1, right = idx + 1;
            vector<int> res = {arr[idx]};
            while (res.size() < k) {
           if (left >= 0 && (right >= n || abs(arr[left] - x) <= abs(arr[right] - x))) {
                    res.push_back(arr[left--]);
                } else {
                    res.push_back(arr[right++]);
                }
            }
            sort(res.begin(), res.end());
            return res;
        }
    }
};