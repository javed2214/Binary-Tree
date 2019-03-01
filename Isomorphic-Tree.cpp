// Program to Check If two Binary Trees are Isomorphic or Not

// Two Trees are called Isomorphic if one of them can be Obtained from Other by a series of Flips, 
// i.e. by swapping left and right children of Nodes.
// Any number of Nodes at any Level can have their Children Swapped. Two Empty Trees are Isomorphic.

bool isomorphicTree(node *root1, node *root2){

	if(root1==NULL and root2==NULL)
		return true;

	if(root1==NULL or root2==NULL)
		return false;

	if(root1->data!=root2->data)
		return false;

	return (isomorphicTree(root1->left,root2->left) and isomorphicTree(root1->right,root2->right)) or 
		   (isomorphicTree(root1->left,root2->right) and isomorphicTree(root1->right,root2->left));
}