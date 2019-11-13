// Root To Leaf Path Sum Equal to a Given Number

// Given a binary tree and a number, return true if the tree has a root-to-leaf path such that adding 
// up all the values along the path equals the given number.
// Return false if no such path can be found.

bool hasPathSum(node *root, int sum){

	if(root == NULL or sum == 0) return 0;
	if(!root->left and !root->right) return ((sum - root->data) == 0);
	return (hasPathSum(root->left, sum - root->data) or hasPathSum(root->right, sum - root->data));
}