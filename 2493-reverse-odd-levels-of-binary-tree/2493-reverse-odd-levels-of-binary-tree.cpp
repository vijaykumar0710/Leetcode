class Solution {
public:
void reverse(vector<TreeNode*>&vec){
    int left=0,right=vec.size()-1;
    while(left<right){
        swap(vec[left]->val,vec[right]->val);
        left++;
        right--;
    }
}
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return NULL;

        queue<TreeNode*>que;
        que.push(root);
        int level=0;

        while(!que.empty()){
            int size=que.size();
            vector<TreeNode*>vec;
            
            for(int i=0;i<size;i++){
                vec.push_back(que.front());

                if(que.front()->left) que.push(que.front()->left);
                if(que.front()->right) que.push(que.front()->right);

                que.pop();
            }
            if(level%2!=0){
                reverse(vec);
            }
            level++;
        }
        return root;
    }
};