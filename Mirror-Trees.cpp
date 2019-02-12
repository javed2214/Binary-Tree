// Program to Check If Two Trees are Mirror Image of Each other or Not

bool isMirror(node *root1, node *root2){

	if(root1==NULL and root2==NULL)
		return true;
	if(root1==NULL or root2==NULL)
		return false;
	return (root1->data==root2->data and isMirror(root1->left, root2->right) and isMirror(root1->right, root2->left));
}