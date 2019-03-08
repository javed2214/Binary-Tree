// Program to Find Minimum Element in Binary Tree

int minElement(node *root){

	if(root==NULL) return INT_MAX;

	int res=root->data;
	int left=minElement(root->left);
	int right=minElement(root->right);

	if(res < left) res=left;
	if(res < right) res=right;

	return res;
}