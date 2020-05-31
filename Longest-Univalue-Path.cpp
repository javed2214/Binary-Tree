// Longest Univalue Path in Binary Tree OR
// Longest Path with Same Value in Binary Tree
// https://www.geeksforgeeks.org/longest-path-values-binary-tree/
// https://leetcode.com/problems/longest-univalue-path/

class Solution {
public:
    
    int mx = 0;
    
    int dfs(TreeNode *root){
        
        if(root == NULL) return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        int leftMax = 0, rightMax = 0;
        
        if(root->left and root->left->val == root->val) leftMax = 1 + left;
        if(root->right and root->right->val == root->val) rightMax = 1 + right;
        
        mx = max(mx, leftMax + rightMax);
        
        return max(leftMax, rightMax);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return mx;
    }
};