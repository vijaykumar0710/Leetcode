class Solution {
public:
vector<int>ans;
void merge(vector<pair<int,int>>&arr,int l,int mid,int r){
      int n1 = mid - l + 1;
        int n2 = r - mid;

       vector<pair<int, int>> L(n1), R(n2);

        int k = l;
        for (int i = 0; i < n1; i++)
            L[i] = arr[k++];
        for (int j = 0; j < n2; j++)
            R[j] = arr[k++];

        int i = 0, j = 0;
        k = l;
        int cnt = 0;

        while (i < n1 && j < n2) {
            if (L[i].first <= R[j].first) {
                ans[L[i].second] += cnt;
                arr[k++] = L[i++];
            } else {
                cnt++;
                arr[k++] = R[j++];
            }
        }

        while (i < n1) {
            ans[L[i].second] += cnt;
            arr[k++] = L[i++];
        }

        while (j < n2) {
            arr[k++] = R[j++];
        }

  }
void mergeSort(vector<pair<int,int>>&arr,int l,int r){
        if(l>=r) return;
        int mid=l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        
        merge(arr,l,mid,r);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        ans.assign(n,0);
        vector<pair<int,int>>pairs;
        for(int i=0;i<n;i++){
            pairs.push_back({nums[i],i});
        }
         mergeSort(pairs,0,n-1);
        return ans;
    }
};