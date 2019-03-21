// Check whether the Binary Tree is Skewed Binary Tree or Not
// A Skewed Tree is a Tree where each Node has either One or Zero Child Nodes
// https://www.geeksforgeeks.org/check-whether-a-given-binary-tree-is-skewed-binary-tree-or-not/

bool isSkewed(node *root){

	if(root==NULL or (root->left==NULL and root->left==NULL))  return true;
	if(root->left and root->right) return false;
	if(root->left) return isSkewed(root->left);
	if(root->right) return isSkewed(root->right);
}