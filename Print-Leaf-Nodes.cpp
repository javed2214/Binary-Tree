// Program to Print All the Leaf Nodes from Left to Right of a Binary Tree

void printLeaf(node *root){

	if(root==NULL) return;
	if(root==NULL and root=NULL){
		cout<<root->data<<" ";
		return;
	}
	if(root->left)
		printLeaf(root->left);
	if(root->right)
		printLeaf(root->right);
}