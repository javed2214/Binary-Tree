// Zig Zag (Spiral) Level Order Traversal - LeetCode
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

class Solution {
public:
	
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector <vector<int>> res;
        
        if(root == NULL) return {};
        
        queue <TreeNode *> q;
        q.push(root);
        
        int flag = 1;
        
        while(!q.empty()){
            
            int siz = q.size();
            vector <int> v(siz);
            
            for(int i=0;i<siz;i++){
                
                TreeNode *temp = q.front();
                q.pop();
                
                if(flag) v[i] = temp->val;
                else v[siz - i - 1] = temp->val;
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            
            res.push_back(v);
            flag = !flag;
        }
        
        return res;
    }
};