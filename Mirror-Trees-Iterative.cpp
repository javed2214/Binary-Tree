// Program to Check Whether two Trees are Mirror of Each other or Not
// Using BFS Approach

bool mirrorTree(node *root1, node *root2){

	if(root1==NULL and root2==NULL) return true;
	if(root1==NULL or root2=NULL) return false;

	queue <node *> q;

	q.push(root1);
	q.push(root2);

	while(!q.empty()){

		node *a,*b;

		a=q.front();
		q.pop();

		b=q.front();
		q.pop();

		if(a->data!=b->data) return false;

		if(a->left and b->right){
			q.push(a->left);
			q.push(b->right);
		}
		else if(a->left or b->right) return false;

		if(a->right and b->left){
			q.push(a->right);
			q.push(b->left);
		}
		else if(a->right or b->left) return false;
	}
	return true;
}
