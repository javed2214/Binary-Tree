// Program to Count BST Nodes that Lie in a Give Range
// https://www.geeksforgeeks.org/count-bst-nodes-that-are-in-a-given-range/

int countNodes(node *root, int low, int high){

	if(root == NULL) return 0;

	if(root->data == high and root->data == low)  // Special Optoional Case for Improving Efficiency
		return 1;

	if(root->data <= high and root->data >= low)
		return 1 + countNodes(root->left, low, high) + countNodes(root->right, low, high);

	else if(root->data < low)
		return countNodes(root->right, low, high);

	else return countNodes(root->right, low, high);
}