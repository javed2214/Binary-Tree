// Program to Check Whether the Tree is Symmetric or Not
// Tree-1 is Symmetric, whereas Tree-2 is Not
// https://leetcode.com/problems/symmetric-tree/

/*

 Tree-1
	1
   / \
  2   2
 / \ / \
3  4 4  3


 Tree-2
	1
   / \
  2   2
   \   \
   3    3

*/

bool symmetricTree(node *root1, node *root2){

	if(root1==NULL and root2==NULL) return true;
	if(root1==NULL or root2==NULL) return false;
	return (root1->data==root2->data and symmetricTree(root1->left, root2->right) and symmetricTree(root1->right, root2->left));
}

int main(){

	symmetricTree(root,root);
}