// Program to Determine If a Binary Tree is Height Balanced or Not
// The Absolute Difference b/w Height of Left and Right Subtree is Not More than 1

// https://leetcode.com/problems/balanced-binary-tree/


// ********************************** METHOD 1 **********************************

// Inefficient Approach
// Time Complexity : O(n^2)  [Worst Case] Else O(nlogn)

int height(node *root){

	if(root == NULL) return 0;
	return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(node *root){

	if(root == NULL) return true;

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	return (abs(leftHeight - rightHeight) <= 1 and isBalanced(root->left) and isBalanced(root->right));
}


// ********************************** METHOD 2 **********************************

// Efficient Approach
// Time Complexity : O(n)

int dfs(node *root){

	if(!root) return 0;

	int leftHeight = dfs(root->left);
	if(leftHeight == -1) return -1;

	int rightHeight = dfs(root->right);
	if(rightHeight == -1) return -1;

	if(abs(leftHeight - rightHeight) > 1) return -1;

	return 1 + max(leftHeight, rightHeight);
}

bool isBalanced(node *root){

	return dfs(root) != -1;
}