// Sum of Left Leaves in a Binary Tree
// https://leetcode.com/problems/sum-of-left-leaves/
// https://www.youtube.com/watch?v=_gnyuO2uquA&list=PLi9RQVmJD2fYckvJZSKA4YcUQ4eyNupuY&index=16

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root){

    	if(root == NULL) return 0;
    	if(root->left and root->left->left == NULL and root->left->right == NULL) return root->left->val + sumOfLeftLeaves(root->right);
    	return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};