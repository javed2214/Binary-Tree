// Flip Equivalent Binary Trees [LeetCode]
// https://leetcode.com/problems/flip-equivalent-binary-trees/


class Solution {
public:
    
    bool go(TreeNode *root1, TreeNode *root2){
       
        if(root1 == NULL and root2 == NULL) return true;
        if(root1 == NULL or root2 == NULL) return false;
        return (root1->val == root2->val) and
            (go(root1->left, root2->left) and go(root1->right, root2->right) or
            go(root1->left, root2->right) and go(root1->right, root2->left));
    }
    
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
        return go(root1, root2);
    }
};