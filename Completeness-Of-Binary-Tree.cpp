// Program to Check whether the Binary Tree is Complete or Not
// In Complete Binary Tree all the Levels except the last Level are Completely filled and
// the Leaves in the Last Level are filled from Left Side
// https://www.geeksforgeeks.org/check-whether-binary-tree-complete-not-set-2-recursive-solution/

bool isComplete(node *root){

	queue <node *> q;
	q.push(root);
	int flag=0;
	while(!q.empty()){
		int siz=q.size();
		for(int i=0;i<siz;i++){
			node *temp=q.front();
			q.pop();
			if(temp==NULL){
				flag=1;
				continue;
			}
			if(flag==1) return false;

			q.push(temp->left);
			q.push(temp->right);
		}
	}
	return true;
}
