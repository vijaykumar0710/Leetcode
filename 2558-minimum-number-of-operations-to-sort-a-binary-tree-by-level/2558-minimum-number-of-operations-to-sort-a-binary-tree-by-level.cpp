class Solution {
public:
int solveSort(vector<int>&vec){
    int n=vec.size();
    int swaps=0;
    vector<int>sortedArr=vec;
    sort(sortedArr.begin(),sortedArr.end());
    unordered_map<int,int>indexMap;
     for (int i = 0; i < n; i++) {
        indexMap[sortedArr[i]] = i;
       }
       for(int i=0;i<n;i++){
        while(vec[i]!=sortedArr[i]){
            swaps++;
            int correctIdx=indexMap[vec[i]];
            swap(vec[i],vec[correctIdx]);
          }
     }
     return swaps;
}
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>que;
        que.push(root);
        int cnt=0;
        while(!que.empty()){
           int n=que.size();
           vector<int>vec;
           for(int i=0;i<n;i++){
            TreeNode* temp=que.front();
            que.pop();
            vec.push_back(temp->val);
           if(temp->left)que.push(temp->left);
           if(temp->right)que.push(temp->right);
           }
         cnt+=solveSort(vec);
        }
      return cnt;
    }
};