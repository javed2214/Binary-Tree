// Program to Determine If a Binary Tree is Height Balanced or Not
// The Absolute Difference b/w Height of Left and Right Subtree is Not More than 1

int height(node *root){

	if(root==NULL) return 0;
	return 1+max(height(root->left),height(root->right));
}

bool isBalanced(node *root){

	int lh,rh;

	if(root==NULL) return true;

	lh=height(root->left);
	rh=height(root->right);

	if(abs(lh-rh)<=1 and isBalanced(root->left) and isBalanced(root->right)) return true;
	return false;
}