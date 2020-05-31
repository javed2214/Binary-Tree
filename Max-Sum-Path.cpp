// Max Sum Path in a Binary Tree
// https://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/
// https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Asked in Most of the Interviews

class Solution {
public:
    
    int mx = INT_MIN;
    
    int dfs(TreeNode *root){
        if(root == NULL) return 0;
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));
        mx = max(mx, left + right + root->val);
        return max(left, right) + root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return mx;
    }
};
