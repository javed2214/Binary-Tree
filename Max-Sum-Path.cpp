// Max Sum Path in a Binary Tree
// https://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/
// https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Asked in Most of the Interviews


int maxSum(node *root, int &res){

	if(root == NULL) return 0;

	int l = maxSum(root->left, res);
	int r = maxSum(root->right, res);

	int max_single = max(max(l,r) + root->data, root->data);

	int max_top = max(max_single, l + r + root->data);

	res = max(res, max_top);

	return max_single;
}

int maxSumPath(node *root){

	int res = INT_MIN;
	maxSum(root, res);

	return res;
}
