// Given a binary tree, return the sum of values of nodes with even-valued grandparent.
// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

class Solution {
public:
    
    int sum = 0;
    
    void dfs(TreeNode *root, TreeNode *parent, TreeNode *grandparent){
        if(root == NULL) return;
        if(grandparent != NULL and grandparent->val % 2 == 0) sum += root->val;
        dfs(root->left, root, parent);
        dfs(root->right, root, parent);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root, NULL, NULL);
        return sum;
    }
};