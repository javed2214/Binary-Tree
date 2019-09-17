// Convert a given Binary Tree to a Tree that holds Logical AND Property
/*
Given a Binary Tree (Every node has at most 2 children) where each node has value either 0 or 1.
Convert a given Binary tree to a tree that holds Logical AND property, i.e.,
each node value should be the logical AND between its children.
*/

void convertTree(node *root){

	if(root == NULL) return;

	convertTree(root->left);
	convertTree(root->right);

	if(root->left != NULL and root->right != NULL)
		root->data = (root->left->data) & (root->right->data);
}