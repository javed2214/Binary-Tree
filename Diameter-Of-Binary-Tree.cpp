// Program to FInd Diameter of Binary Tree
// The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes
// Time Complexity : O(n^2) 

int height(node *root){

	if(root==NULL) return 0;
	return 1+max(height(root->left), height(root->right));
}

int treeDiameter(node *root){

	if(root==NULL) return 0;
	
	int lheight=height(root->left);
	int rheight=height(root->right);
	int ldiameter=treeDiameter(root->left);
	int rdiameter=treeDiameter(root->right);

	int td=max(1+lheight+rheight, max(ldiameter, rdiameter));

	return td;
}