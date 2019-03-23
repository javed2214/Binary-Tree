// To Check whether the Binary Tree is Foldable or Not

bool isFoldable(node *root){

	if(root==NULL) return true;
	return foldableUtil(root->left, root->right);
}

bool foldableUtil(node *n1, node *n2){

	if(n1==NULL and n2==NULL) return true;
	if(n1==NULL or n2==NULL) return false;

	return foldableUtil(n1->left, n2->right) and foldableUtil(n1->right, n2->left);
}

int main(){

	cout<<isFoldable(root);
}