// Iterative Preorder Traversal of a Binary Tree

void iterativePreorder(node *root){

	if(root==NULL) return;

	stack <node *> S;
	S.push(root);

	while(!S.empty()){

		node *p=S.top();
		S.pop();
		cout<<p->data<<" ";

		if(p->right) S.push(p->right);
		if(p->left) S.push(p->left);
	}
}