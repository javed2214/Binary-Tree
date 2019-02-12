// Program to Check Whether Tree is Subtree of Another Tree or Not
// root2 is subtree of root1 or Not

bool isIdentical(node *root1, node *root2){
	if(root1==NULL and root2==NULL)
		return true;
	if(root1==NULL or root2==NULL)
		return false;
	return (root1->data==root2->data and (isIdentical(root1->left, root2->left) and isIdentical(root1->right, root2->right)));
}

bool SubTree(node *root1, node *root2){
	if(root2==NULL) return true;
	if(root1==NULL) return false;
	if(isIdentical(root1,root2))
		return true;
	return (Subtree(roor1->left, root2) || Subtree(root1->right, root2));
}