// Reverse Level Order Traversal (Iterative)
// https://www.geeksforgeeks.org/reverse-level-order-traversal/

void reverseLOT(node *root){

	queue<node *> Q;
	stack<node *> S;

	Q.push(root);

	while(!Q.empty()){

		node *temp=Q.front();
		Q.pop();
		S.push(temp);

		if(temp->right) Q.push(temp->right);
		if(temp->left) Q.push(temp->left);
	}
	while(!S.empty()){

		node *temp=S.top();
		S.pop();
		cout<<temp->data<<" ";
	}
}