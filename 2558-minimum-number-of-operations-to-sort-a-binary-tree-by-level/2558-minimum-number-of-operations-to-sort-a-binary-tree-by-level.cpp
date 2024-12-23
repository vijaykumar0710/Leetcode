class Solution {
public:
int solveSort(vector<int>&vec){
    int n=vec.size();
    vector<pair<int,int>>sortedArr(n);
    for(int i=0;i<n;i++){
        sortedArr[i]={vec[i],i};
    }
   sort(sortedArr.begin(),sortedArr.end());
   vector<bool>visited(n,false);
   int swaps=0;
   for(int i=0;i<n;i++){
    if(visited[i]||sortedArr[i].second==i){
        continue;
    }
    int cycleSize=0;
    int j=i;
    while(!visited[j]){
        visited[j]=true;
        j=sortedArr[j].second;
        cycleSize++;
      }
     if(cycleSize>1){
        swaps+=(cycleSize-1);
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