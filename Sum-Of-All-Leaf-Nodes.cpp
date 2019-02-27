// Program to Print Sum of All Leaf Nodes of a Binary Tree

void leafSum(node *root, int *sum){
 
	if(root==NULL) return;
	if(root->left==NULL and root->right==NULL)
		*sum+=root->data;
	leafSum(root->left);
	leafSum(root->right);
}

int main(){

	int sum=0;
	node *root;
	leafSum(root,&sum);
	cout<<sum;

	return 0;
}