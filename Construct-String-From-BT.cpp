// Construct String from Binary Tree
// https://leetcode.com/problems/construct-string-from-binary-tree/
// https://www.youtube.com/watch?v=UVafek_SnXE

string constructString(node *root){

	if(root == NULL) return "";

	if(root->left == NULL and root->right == NULL) return to_string(root->data);

	leftString = constructString(root->left);
	rightString = constructString(root->right);

	if(rightString == "") return to_string(root->data) + "(" + leftString + ")";
	else return to_string(root->data) + "(" + leftString + ")" + "(" + rightString + ")";
}