// Pogram to Print Odd Nodes of Binary Tree

void printOddNodes(node *root){

	if(root){
		printOddNodes(root->left);
		if(root->data & 1) cout<<root->data<<" ";
		printOddNodes(root->right);
	}
}


// For Even Nodes

void printEvenNodes(node *root){

	if(root){
		printEvenNodes(root->left);
		if(root->data % 2 == 0) cout<<root->data<<" ";
		printEvenNodes(root->right);
	}
}