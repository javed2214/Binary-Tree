// Program to Print BST Nodes in a Given Range
// https://www.geeksforgeeks.org/print-bst-keys-in-the-given-range/

void printBSTNodes(node *root, int k1, int k2){

	if(root == NULL) return;

	if(root->data > k1) printBSTNodes(root->left, k1, k2);

	if(root->data >= k1 and root->data <= k2) cout<<root->data<<" ";

	if(root->data < k2) printBSTNodes(root->right, k1, k2);
}