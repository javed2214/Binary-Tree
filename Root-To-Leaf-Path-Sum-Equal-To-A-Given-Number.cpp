// Root To Leaf Path Sum Equal to a Given Number
// https://leetcode.com/problems/path-sum/

// Given a binary tree and a number, return true if the tree has a root-to-leaf path such that adding 
// up all the values along the path equals the given number.
// Return false if no such path can be found.

// ******************************** METHOD 1 ********************************

bool hasPathSum(node *root, int sum){

	if(root == NULL or sum == 0) return 0;
	if(!root->left and !root->right) return ((sum - root->data) == 0);
	return (hasPathSum(root->left, sum - root->data) or hasPathSum(root->right, sum - root->data));
}


// ******************************** METHOD 2 ********************************

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        
        if(!root) return false;
        sum -= root->val;
        if(!root->left and !root->right and !sum) return true;
        return hasPathSum(root->left, sum) or hasPathSum(root->right, sum);
    }
};
