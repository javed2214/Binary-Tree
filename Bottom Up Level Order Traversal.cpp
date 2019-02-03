// Bottom Up Level Order Traversal
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if(root==NULL) return {};
        
        vector <vector<int>> res;
        queue <TreeNode *> q;
        q.push(root);
        int count=1,cur;
        while(!q.empty()){
            cur=0;
            vector<int> v;
            while(count--){
                TreeNode *ptr=q.front();
                q.pop();
                v.push_back(ptr->val);
                if(ptr->left){
                    q.push(ptr->left);
                    cur++;
                }
                if(ptr->right){
                    q.push(ptr->right);
                    cur++;
                }
            }
            res.insert(res.begin(),v);
            count=cur;
        }
        return res;
    }
};
