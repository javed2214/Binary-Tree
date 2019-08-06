// BST to Greater Sum Tree
// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/


class Solution {
public:
    
    void nodeSum(TreeNode *root, int &sum){
        
        if(!root) return;
        nodeSum(root->right, sum);
        root->val += sum;
        sum = root->val;
        nodeSum(root->left, sum);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        
        int sum = 0;
        nodeSum(root,sum);
        
        return root;
    }
};