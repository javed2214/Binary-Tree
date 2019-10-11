// Distribute Coins in Binary Tree
// https://leetcode.com/problems/distribute-coins-in-binary-tree/
// https://www.geeksforgeeks.org/distribute-candies-in-a-binary-tree/

class Solution {
public:
    
    int res = 0;
    
    int dfs(TreeNode *root){
        
        if(root == NULL) return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        res += abs(left) + abs(right);
        
        return root->val + left + right - 1;
    }
    
    int distributeCoins(TreeNode* root) {
        
        dfs(root);
        
        return res;
    }
};